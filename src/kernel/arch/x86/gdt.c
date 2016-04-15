#include "kernel/arch/x86/gdt.h"

struct __gdt_entry {
    unsigned short _limit_low;
    unsigned short _base_low;
    unsigned char  _base_middle;
    unsigned char  _access;
    unsigned char  _granularity;
    unsigned char  _base_high;
} __attribute__((packed));

struct __gdt_ptr {
    unsigned short _limit;
    unsigned int   _base;
} __attribute__((packed));

typedef struct __gdt_entry gdt_entry_t;
typedef struct __gdt_ptr gdt_ptr_t;

gdt_entry_t gdt_entries[6];
gdt_ptr_t   gdt_ptr;

static void gdt_set_gate( int num, 
                          unsigned int base, 
                          unsigned int limit, 
                          unsigned char access, 
                          unsigned char gran ) {
    gdt_entries[ num ]._base_low = (base & 0xffff);
    gdt_entries[ num ]._base_middle = (base >> 16) & 0xff;
    gdt_entries[ num ]._base_low    = (base >> 24) & 0xff;
    
    gdt_entries[ num ]._limit_low = limit & 0xffff;
    gdt_entries[ num ]._granularity = (limit >> 16) & 0x0f;
    
    gdt_entries[ num ]._granularity |= gran & 0xf0;
    gdt_entries[ num ]._access = access;
}

void init_gdt() {
    gdt_ptr._limit = (sizeof(gdt_entry_t) * 6) - 1;
    gdt_ptr._base = (unsigned int)&gdt_entries;
    
    /**
     * 0xcf     1100 1111
     *          Gr -> 1 [  Granularity bit. If 0 the limit is in 1 B blocks (byte granularity), if 1 the limit is in 4 KiB blocks (page granularity). ]
     *          Sz -> 1 [ Size bit. If 0 the selector defines 16 bit protected mode. If 1 it defines 32 bit protected mode. You can have both 16 bit and 32 bit selectors at once. ]
     */
    
    gdt_set_gate( 0, 0, 0, 0, 0 );                      // NULL segnemt
    gdt_set_gate( 1, 0, 0xffffffff, 0x9a, 0xcf );       // kernel CS
    gdt_set_gate( 2, 0, 0xffffffff, 0x92, 0xcf );       // kernel DS
    gdt_set_gate( 3, 0, 0xffffffff, 0xfa, 0xcf );       // user CS
    gdt_set_gate( 4, 0, 0xffffffff, 0xf2, 0xcf );       // user DS
    gdt_set_gate( 5, 0, 0, 0, 0 );
    
    asm volatile( "lgdt (%0)\n"
                  "mov $0x10, %%eax\n"
                  "mov %%eax, %%ds\n"
                  "mov %%eax, %%es\n"
                  "mov %%eax, %%fs\n"
                  "mov %%eax, %%gs\n"
                  "mov %%eax, %%ss\n"
                  "jmp $0x08, $.flush\n\n" : : "m"(gdt_ptr) );
      
    asm volatile( ".flush:\n" );
}

#include "kernel/multiboot.h"
#include "kernel/console.h"
#include "kernel/arch/x86/cpu.h"
#include "kernel/arch/x86/gdt.h"
#include "kernel/arch/x86/idt.h"

void init_descriptor_table() {
    init_gdt();
    init_idt();
}


typedef struct _Arguments {
    unsigned long magic;
    unsigned long address;
}Arguments;

#if defined(__cplusplus)
extern "C" /* Use C linkage for _kmain. */
#endif
//void _kmain( unsigned long magic, unsigned long address ) {
void _kmain( Arguments args ) {
    
    init_descriptor_table();
    
    console_init();
    
    console_clear();
    const char* string = "Hello World!!!";

    console_printf( "%s [0x%lX]\n", string, args.magic );
    enable_interrupt();
    //asm volatile ("int $0x3");
    asm volatile ("int $0x0");
}

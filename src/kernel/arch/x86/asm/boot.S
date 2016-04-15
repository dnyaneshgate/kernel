
#define ASM_FILE
#include "kernel/multiboot.h"


/*
 * 16 KB stack
 */
#define STACK_SIZE 0x4000

#define MULTIBOOT_HEADER_FLAGS (MULTIBOOT_PAGE_ALIGN | MULTIBOOT_MEMORY_INFO | MULTIBOOT_VIDEO_MODE)
#define MULTIBOOT_HEADER_CHECKSUM -(MULTIBOOT_HEADER_MAGIC+MULTIBOOT_HEADER_FLAGS)

.section .msection
.align 4
multiboot_header:
    .long MULTIBOOT_HEADER_MAGIC
    .long MULTIBOOT_HEADER_FLAGS
    .long MULTIBOOT_HEADER_CHECKSUM
    .long multiboot_header
    .long __text_start
    .long __bss_start
    .long __kernel_end
    .long multiboot_entry


.text
    .global start, _start

start:
_start:
    jmp multiboot_entry


multiboot_entry:
    cli
    movl $(stack + STACK_SIZE), %esp

    // reset EFLAGS
    pushl $0
    popf

    // push the pointer to multiboot information structure
    pushl %ebx

    // push magic value
    pushl %eax

    call _kmain

loop:
    hlt
    jmp loop

.bss
    .comm stack, STACK_SIZE


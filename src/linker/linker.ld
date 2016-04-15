/*
 *  * OUTPUT FORMAT:
 *   * binary --This is just a flat binary with no formatting at all
 *    * elf32-i386 --This is just the ELF format, usually little endian too.
 *     * elf64-x86-64 --This is the ELF format for 64bit, usually little endian.
 *      * pe-i386 --The PE format
 *       */


/* Generate an ELF executable */
OUTPUT_FORMAT("elf32-i386")

/* Set the entry point to 'start'. This is an assembly function, so there's
 * * no name mangling */
ENTRY(_start)
SECTIONS
{
    /* The executable is to be loaded by GrUB at 1 Mib */
    . = 0x00100000;
    
    /* Align every section on page boundaries. This'll be important later on */
    
    .text ALIGN(0x1000) :
    {
        *(.msection*)
        
        /* This marks the start of the program code */
        __text_start = .;
        
        /* GrUB requires that the Multiboot header be located at the start
         *      * of the file */
        *(.text*)
        *(.gnu.linkonce.t*)
        *(.gnu.linkonce.r*)

        __text_end = .;
                                }

    /* This section contains our local variables and constructor (and destructor) lists */
    .data ALIGN(0x1000) :
    {
        __data_start = .;

        __CTOR_LIST__ = .; LONG((__CTOR_END__ - __CTOR_LIST__) / 4 - 2) *(.init_array*) LONG(0) __CTOR_END__ = .;
        __DTOR_LIST__ = .; LONG((__DTOR_END__ - __DTOR_LIST__) / 4 - 2) *(.fini_array*) LONG(0) __DTOR_END__ = .;

        KEEP(*(.ctor*))
        KEEP(*(.ctor*))

        __init_start__ = .;
        *(.init*)
        KEEP(*(SORT(.init*)))
        /*KEEP(*(.init*))*/
        __init_end__ = .;

        *(.rodata*)
        *(.data*)
        *(.gnu.linkonce.d*)

        __data_end = .;
    }

    /* There isn't really anything interesting here. It gets
     * zeroed out by GrUB before
     *  * the kernel is executed */
    .bss ALIGN(0x1000) :
    {
        __bss_start = .;

        *(.gnu.linkonce.b*)
        *(COMMON)
        *(.bss*)

        __bss_end = .;
    }

    __kernel_end = .;
}


#include "kernel/multiboot.h"
#include "kernel/console.hpp"
#include "kernel/arch/x86/gdt.h"

void init_descriptor_table() {
    init_gdt();
}

#if defined(__cplusplus)
extern "C" /* Use C linkage for _kmain. */
#endif
void _kmain( unsigned long magic, unsigned long address ) {
    
    init_descriptor_table();
    
    io::console::clear();
    const char* string = "Hello World!!!";

    io::console::printf( "%s [0x%lX]", string, magic );
}

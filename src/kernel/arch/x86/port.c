

#include "kernel/arch/x86/port.h"


void inb( unsigned short _port, unsigned char* result ) {
     asm volatile ("inb %1,%0;" : "=a"(*result) : "dN"(_port));
}

void inw( unsigned short _port, unsigned short* result ) {
    asm volatile ("inw %1,%0;" : "=a"(*result) : "dN"(_port));
}

void inl( unsigned short _port, unsigned long* result ) {
    asm volatile ("inl %1,%0;" : "=a"(*result) : "dN"(_port));
}

void outb( unsigned short _port, unsigned char value ) {
    asm volatile ( "outb %1, %0" : : "dN"(_port), "a"(value) );
}

void outw( unsigned short _port, unsigned short value ) {
    asm volatile ( "outw %1, %0" : : "dN"(_port), "a"(value) );
}

void outl( unsigned short _port, unsigned long value ) {
    asm volatile ( "outl %1, %0" : : "dN"(_port), "a"(value) );
}



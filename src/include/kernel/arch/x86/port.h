#ifndef __SRC_INCLUDE_KERNEL_ARCH_X86_PORT_H__
#define __SRC_INCLUDE_KERNEL_ARCH_X86_PORT_H__

void inb( unsigned short _port, unsigned char* result );

void inw( unsigned short _port, unsigned short* result );

void inl( unsigned short _port, unsigned long* result );

void outb( unsigned short _port, unsigned char value );

void outw( unsigned short _port, unsigned short value );

void outl( unsigned short _port, unsigned long value );        


#endif //__SRC_INCLUDE_KERNEL_ARCH_X86_PORT_H__

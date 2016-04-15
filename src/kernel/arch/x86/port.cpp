

#include "kernel/arch/x86/port.hpp"

namespace io {
    
    namespace port {
        
        void ReadByte( unsigned short _port, unsigned char* result ) {
             asm volatile ("inb %1,%0;" : "=a"(*result) : "dN"(_port));
        }
        
        void ReadWord( unsigned short _port, unsigned short* result ) {
            asm volatile ("inw %1,%0;" : "=a"(*result) : "dN"(_port));
        }
        
        void ReadLong( unsigned short _port, unsigned long* result ) {
            asm volatile ("inl %1,%0;" : "=a"(*result) : "dN"(_port));
        }
        
        void WriteByte( unsigned short _port, unsigned char value ) {
            asm volatile ( "outb %1, %0" : : "dN"(_port), "a"(value) );
        }
        
        void WriteWord( unsigned short _port, unsigned short value ) {
            asm volatile ( "outw %1, %0" : : "dN"(_port), "a"(value) );
        }
        
        void WriteLong( unsigned short _port, unsigned long value ) {
            asm volatile ( "outl %1, %0" : : "dN"(_port), "a"(value) );
        }
        
    } /* namespace port */
    
} /* namespace io */


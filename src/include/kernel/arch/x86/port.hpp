#ifndef __SRC_INCLUDE_KERNEL_ARCH_X86_PORT_HPP__
#define __SRC_INCLUDE_KERNEL_ARCH_X86_PORT_HPP__

namespace io {
    
    namespace port {
        
        void ReadByte( unsigned short _port, unsigned char* result );
        
        void ReadWord( unsigned short _port, unsigned short* result );
        
        void ReadLong( unsigned short _port, unsigned long* result );
        
        void WriteByte( unsigned short _port, unsigned char value );
        
        void WriteWord( unsigned short _port, unsigned short value );
        
        void WriteLong( unsigned short _port, unsigned long value );        
        
    } /* namespace port */
    
} /* namespace io */

#endif //__SRC_INCLUDE_KERNEL_ARCH_X86_PORT_HPP__

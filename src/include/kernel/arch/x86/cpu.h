#ifndef __SRC_INCLUDE_KERNEL_ARCH_X86_CPU_H__
#define __SRC_INCLUDE_KERNEL_ARCH_X86_CPU_H__

#define disable_interrupt() asm volatile("cli\n")
#define enable_interrupt()  asm volatile("sti\n")

#endif //__SRC_INCLUDE_KERNEL_ARCH_X86_CPU_H__

#ifndef __SRC_INCLUDE_KERNEL_ARCH_X86_IDT_H__
#define __SRC_INCLUDE_KERNEL_ARCH_X86_IDT_H__

#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

void init_idt();

#ifdef __cplusplus
}
#endif

#endif //__SRC_INCLUDE_KERNEL_ARCH_X86_IDT_H__

.macro REGISTER_SAVE
    pushal                  // Push EAX, ECX, EDX, EBX, original ESP, EBP, ESI, and EDI.
    pushl %ss
    pushl %ds
    pushl %es
    pushl %fs
    pushl %gs
    mov $0x10, %ax
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs
.endm

.macro REGISTER_RESTORE
    popl %gs
    popl %fs
    popl %es
    popl %ds
    popal
.endm

.macro ISR_NOERRCODE num
.global isr\num
isr\num:
    cli
    pushl $0
    pushl \num
    jmp isr_common_stub
.endm

.macro ISR_ERRCODE num
.global isr\num
isr\num:
    cli
    pushl \num
    jmp isr_common_stub
.endm


.extern isr_handler
isr_common_stub:
    REGISTER_SAVE
    call isr_handler
    REGISTER_RESTORE
    addl $8, %esp
    sti
    iretl
    
ISR_NOERRCODE 0
ISR_NOERRCODE 1
ISR_NOERRCODE 2
ISR_NOERRCODE 3
ISR_NOERRCODE 4
ISR_NOERRCODE 5
ISR_NOERRCODE 6
ISR_NOERRCODE 7
ISR_ERRCODE 8
ISR_NOERRCODE 9
ISR_ERRCODE 10
ISR_ERRCODE 11
ISR_ERRCODE 12
ISR_ERRCODE 13
ISR_ERRCODE 14
ISR_NOERRCODE 15
ISR_NOERRCODE 16
ISR_NOERRCODE 17
ISR_NOERRCODE 18
ISR_NOERRCODE 19
ISR_NOERRCODE 20
ISR_NOERRCODE 21
ISR_NOERRCODE 22
ISR_NOERRCODE 23
ISR_NOERRCODE 24
ISR_NOERRCODE 25
ISR_NOERRCODE 26
ISR_NOERRCODE 27
ISR_NOERRCODE 28
ISR_NOERRCODE 29
ISR_NOERRCODE 30
ISR_NOERRCODE 31

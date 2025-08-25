section .boot64_code
bits 64

global long_mode_start
extern kmain

section .boot64_code
bits 64

long_mode_start:
    ; load null into all data segment registers
    mov ax, 0
    mov ss, ax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov rax, kmain
    call rax
    hlt

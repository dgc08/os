global kmain_test

section .text
bits 64
kmain_test:
    ; print `OK` to screen
    mov dword [0xb8000], 0x2f4b2f4f
    mov dword [0xb8004], 0x2f4f2f4f
    hlt

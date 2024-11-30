global acpi_poweroff
    
section .text
bits 64
acpi_poweroff:
    ; Attempt ACPI shutdown via QEMU's ACPI port
    mov dx, 0x604    ; ACPI shutdown port (QEMU-specific)
    mov ax, 0x2000   ; Value to signal power off
    out dx, ax       ; Write to the ACPI port

    mov     eax, 0x01
    ret

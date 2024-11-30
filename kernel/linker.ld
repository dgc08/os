/* Tell the linker that we want an x86_64 ELF64 output file */
/* OUTPUT_FORMAT(elf64-x86-64) */

/* We want the symbol kmain to be our entry point */
ENTRY(kmain)

/* /\* Program headers are optional for Multiboot 2 but can be included *\/ */
/* PHDRS */
/* { */
/*     multiboot_header PT_LOAD FLAGS(0x05); /\* Read/Execute *\/ */
/*     text PT_LOAD FLAGS(0x05);             /\* Read/Execute *\/ */
/*     rodata PT_LOAD FLAGS(0x04);           /\* Read-only *\/ */
/*     data PT_LOAD FLAGS(0x06);             /\* Read/Write *\/ */
/* } */

/* Define sections and layout */
SECTIONS
{
    . = 1M;

    .boot :
    {
        /* ensure that the multiboot header is at the beginning */
        *(.multiboot_header)
        KEEP(*(.multiboot_header))
    }

    /* Code section (.text) */
    . = ALIGN(CONSTANT(MAXPAGESIZE));
    .text : {
        *(.text .text.*)
    }

    /* Move to the next memory page for .rodata */
    . = ALIGN(CONSTANT(MAXPAGESIZE));

    .rodata : {
        *(.rodata .rodata.*)
    }

    /* Move to the next memory page for .data */
    . = ALIGN(CONSTANT(MAXPAGESIZE));

    .data : {
        *(.data .data.*)
    }

    /* NOTE: .bss needs to be the last thing mapped to :data, otherwise lots of */
    /* unnecessary zeros will be written to the binary. */
    /* If you need, for example, .init_array and .fini_array, those should be placed */
    /* above this. */
    .bss : {
        *(.bss .bss.*)
        *(COMMON)
    }

    /* Discard .note.* and .eh_frame* since they may cause issues on some hosts. */
    /DISCARD/ : {
        *(.eh_frame*)
        *(.note .note.*)
    }
}

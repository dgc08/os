#include <stddef.h>
#include <stdint.h>

#include <lib.h>
#include <drivers/VGA_text.h>

static inline void hcf(void) {
    while (1) {
        asm ("hlt");
    }
}
void acpi_poweroff(void);
void poweroff(void) {
    acpi_poweroff();
    puts("Poweroff failed\n");
    hcf();
}

void kmain(void) {
    char buf [33];
    itoa(35+34, buf, 16);
    puts(buf);
    puts("\n");
    puts("Hello, World!\n");
    puts("Hallo, Welt!\n");
    puts("Hallo, Welt!\n");
    puts("Hallo, Welt!\n");
    puts("Hallo, Welt!\n");
    puts("Hallo, Welt!\n");
    puts("Hallo, Welt!\n");
    puts("Hallo, Welt!\n");
    hcf();
}

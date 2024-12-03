#include <stddef.h>
#include <stdint.h>

#include <lib.h>
#include <drivers/tty.h>
#include <iolib.h>

void acpi_poweroff_qemu(void);
void poweroff (void) {
    acpi_poweroff_qemu();
    puts("Poweroff failed, you are probably not using QEMU\n");
    hcf();
}


void kmain (void) {
    char buf [33];
    buf[0] = ' ';
    for (int i = 0; i < 26; i++) {
        putc('A'+i);
        buf[0] = ' ';

        Vector2 pos = tty_get_cursor_vector();

        itoa(pos.y, buf+1, 10);
        puts(buf);
        putc(':');
        itoa(pos.x, buf, 10);
        puts(buf);
        putc('\n');
    }
    //puts("lol");

    hcf();
}

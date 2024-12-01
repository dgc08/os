#include <stddef.h>
#include <stdint.h>

#include <lib.h>
#include <drivers/tty.h>

static inline void hcf (void) {
    while (1) {
        asm ("hlt");
    }
}

void acpi_poweroff(void);
void poweroff (void) {
    acpi_poweroff();
    puts("Poweroff failed\n");
    hcf();
}

void kmain (void) {
    char buf [33];
    buf[0] = ' ';
    for (int i = 0; i < 25; i++) {
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
    //puts("Guten morgen.sdfhjdgsfjhdsgfjdsgggfdsjgfggsddsfdsfdsfdsgfssjsdhfgsdjhfgsdjgfdjshgfdjh\nguten tag");

    hcf();
}

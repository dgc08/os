#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <stdio.h>
#include <iolib.h>

#include <drivers/tty.h>
#include "drivers/keyboard_hardware.h"
#include "drivers/keyboard_layouts.h"

#include <lib.h>
#include <lib/queue.h>

#include <se-sh/se-target.h>

void acpi_poweroff_qemu(void);
void poweroff (void) {
    acpi_poweroff_qemu();
    puts("Poweroff failed, you are probably not using QEMU\n");
    hcf();
}


void kmain (void) {
    //dbbreak();

    set_keyboard_layout("de");

    target_shell();
    poweroff();

    while(1) {
        putc(getch());
        get_keycode();
    }

    while (1) {
        puts("here: ");
        for (uint8_t i=0; i < 128; i++) {
            get_keycode();
            if (check_key(i)) {
               printf("%d ", i);
            }
        }
        puts("\n");
    }

    /* char buf [33]; */
    /* buf[0] = ' '; */
    /* for (int i = 0; i < 26; i++) { */
    /*     putc('A'+i); */
    /*     buf[0] = ' '; */

    /*     Vector2 pos = tty_get_cursor_vector(); */

    /*     itoa(pos.y, buf+1, 10); */
    /*     puts(buf); */
    /*     putc(':'); */
    /*     itoa(pos.x, buf, 10); */
    /*     puts(buf); */
    /*     putc('\n'); */
    /* } */
    hcf();
}

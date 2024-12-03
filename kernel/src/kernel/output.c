#include <lib.h>
#include <drivers/tty.h>
#include <iolib.h>

char iota_buf[33];

void kernel_panic (int code, char* msg) {
    tty_set_cursor_scalar(0);
    puts("\n**********************************KERNEL PANIC**********************************\n");
    puts("Please restart.\n\n\n");
    puts(msg);
    puts("\nError code 0x");
    itoa(code, iota_buf, 16);
    puts(iota_buf);

    puts("\n");
    puts("\n********************************************************************************\n");
    hcf();
}

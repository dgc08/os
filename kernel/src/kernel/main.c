#include <lib.h>
#include <stddef.h>
#include <stdint.h>

#define WHITE 0x07

static volatile char* const video = (char*) 0xb8000;
static volatile size_t cursor_pos = 0;

void putc (char c, uint8_t color) {
    video[cursor_pos++] = c;
    video[cursor_pos++] = color;
}

void puts (const char* s, uint8_t color) {
    while (*s != 0) {
        putc(*s++, color);
    }
}

void kmain(void) {
    puts("Hello, World!", WHITE);
    dbbreak();
    puts(" Hallo, Welt!", WHITE);
    hcf();
}

#include "VGA_text.h"
#include <iolib.h>

static volatile char* const video = (char*) VGA_VIDEO_ADDRESS;
static volatile size_t cursor_pos = 0;

static uint8_t color = 0x07;

void set_cursor(int offset) {
    offset /= 2;
    outb(VGA_CTRL_REGISTER, VGA_OFFSET_HIGH);
    outb(VGA_DATA_REGISTER, (unsigned char) (offset >> 8));
    outb(VGA_CTRL_REGISTER, VGA_OFFSET_LOW);
    outb(VGA_DATA_REGISTER, (unsigned char) (offset & 0xff));
}

int getVGACursor() {
    outb(VGA_CTRL_REGISTER, VGA_OFFSET_HIGH);
    int offset = inb(VGA_DATA_REGISTER) << 8;
    outb(VGA_CTRL_REGISTER, VGA_OFFSET_LOW);
    offset += inb(VGA_DATA_REGISTER);
    return offset * 2;
}

void putc(char c) {
    if (c == '\n') {
        cursor_pos = (cursor_pos / VGA_COLS+1) * VGA_COLS;
        if (cursor_pos >= VGA_ROWS * VGA_COLS * 2)
            cursor_pos = 0;
        set_cursor(cursor_pos);
        return;
    }
    video[cursor_pos++] = c;
    video[cursor_pos++] = color;
    set_cursor(cursor_pos);
}

void puts (const char* s) {
    while (*s != 0) {
        putc(*s++);
    }
}

void set_color_byte(const uint8_t new_color) {
    color = new_color;
}

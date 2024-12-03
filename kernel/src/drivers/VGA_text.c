#include "VGA_text.h"
#include "lib.h"
#include <iolib.h>

static volatile char* const video = (char*) VGA_VIDEO_ADDRESS;

void VGA_set_cursor (int offset) {
    outb(VGA_CTRL_REGISTER, VGA_OFFSET_HIGH);
    outb(VGA_DATA_REGISTER, (uint8_t) (offset >> 8));
    outb(VGA_CTRL_REGISTER, VGA_OFFSET_LOW);
    outb(VGA_DATA_REGISTER, (uint8_t) (offset & 0xff));
}

int VGA_get_cursor () {
    outb(VGA_CTRL_REGISTER, VGA_OFFSET_HIGH);
    int offset = inb(VGA_DATA_REGISTER) << 8;
    outb(VGA_CTRL_REGISTER, VGA_OFFSET_LOW);
    offset += inb(VGA_DATA_REGISTER);
    return offset;
}

void VGA_put_char(char c, uint8_t color, uint32_t pos) {
    pos *= 2;
    video[pos] = c;
    video[pos+1] = color;
}

VGA_character VGA_get_char(uint32_t pos) {
    pos *= 2;
    VGA_character ret;
    ret.c = video[pos];
    ret.color = video[pos+1];

    return ret;
}

void VGA_clear_screen () {
    for (int i = 0; i < (VGA_COLS * VGA_ROWS); ++i) {
        VGA_put_char(' ', VGA_WHITE, i);
    }
    VGA_set_cursor(0);
}

inline uint8_t gen_color (uint8_t fg, uint8_t bg) {
    return fg | bg << 4;
}

#include "tty.h"
#include "VGA_text.h"

static volatile int cursor_pos = 0;

static uint8_t color = VGA_LIGHT_GRAY | VGA_BLACK << 4;

void putc (char c) {
    if (c == '\n') {
        cursor_pos = (cursor_pos/VGA_COLS + 1) * VGA_COLS;
        if (cursor_pos >= VGA_ROWS * VGA_COLS)
            cursor_pos = 0;
    }
    else {
        VGA_put_char(c, color, cursor_pos);
        cursor_pos++;
    }
    VGA_set_cursor(cursor_pos);
}

void puts (const char* s) {
    while (*s != 0) {
        putc(*s++);
    }
}

void set_color_byte (uint8_t new_color) {
    color = new_color;
}

int tty_get_cursor_scalar () {
    return cursor_pos;
}

Vector2 tty_get_cursor_vector () {
    return (Vector2) {
        .x = cursor_pos % VGA_COLS,
        .y = cursor_pos / VGA_COLS
    };
}

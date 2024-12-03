#include "tty.h"
#include <lib.h>
#include <iolib.h>
#include <drivers/VGA_text.h>

static volatile int cursor_pos = 0;

static uint8_t color = VGA_LIGHT_GRAY | VGA_BLACK << 4;

void putc (char c) {
    if (cursor_pos > (VGA_ROWS * VGA_COLS)-1 || (c == '\n' && (cursor_pos / VGA_COLS)+1 >= VGA_COLS)) {
            tty_scroll_down(1);
    }
    if (c == '\n') {
        for (int i = 0; i <= cursor_pos%VGA_COLS; i++)
            putc(' ');
        putc(0);
    }
    else if (c == 0) {}
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

void tty_write(const char* data, size_t size) {
    for (size_t i = 0; i < size; i++)
        putc(data[i]);
}

void tty_set_color_byte (uint8_t new_color) {
    color = new_color;
}


void tty_set_cursor_scalar (int new_cursor) {
    cursor_pos = new_cursor;
    VGA_set_cursor(cursor_pos);
}
void tty_set_cursor_vector (Vector2 new_cursor) {
    cursor_pos = new_cursor.y*VGA_COLS + new_cursor.x;
    VGA_set_cursor(cursor_pos);
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

void tty_scroll_down (int amount) {
    for ( ; amount != 0; amount--) {
        for (int pos = VGA_COLS; pos < (VGA_ROWS) * VGA_COLS; pos++) {
            VGA_character c = VGA_get_char(pos);
            dbbreak();
            VGA_put_char(c.c, c.color, pos-VGA_COLS);
        }
        tty_set_cursor_vector((Vector2) {.x = 0, .y = VGA_ROWS-1});
        for (int i = 0; i < VGA_COLS; i++)
            putc(' ');
        tty_set_cursor_vector((Vector2) {.x = 0, .y = VGA_ROWS-1});
    }
    //hcf();
}

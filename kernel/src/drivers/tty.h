#ifndef TTY_H_
#define TTY_H_

#include <lib.h>

#include <stdint.h>
#include <stddef.h>

void putc(char c);
void puts(const char* s);
void set_color_byte(const uint8_t new_color);

int tty_get_cursor_scalar();

Vector2 tty_get_cursor_vector();

#endif // TTY_H_

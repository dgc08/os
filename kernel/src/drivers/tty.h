#ifndef TTY_H_
#define TTY_H_

#include <lib.h>

#include <stdint.h>
#include <stddef.h>

int putc(char c);
int puts(const char* s);
void tty_write(const char* data, size_t size);
void tty_set_color_byte(const uint8_t new_color);

int tty_get_cursor_scalar();
Vector2 tty_get_cursor_vector();

void tty_set_cursor_scalar(int new_cursor);
void tty_set_cursor_vector(Vector2 new_cursor);

void tty_scroll_down(int amount);

char getch();

#endif // TTY_H_

#ifndef VGA_TEXT_H_
#define VGA_TEXT_H_

#include <stdint.h>
#include <stddef.h>

#define VGA_BLACK 0
#define VGA_BLUE 1
#define VGA_GREEN 2
#define VGA_CYAN 3
#define VGA_RED 4
#define VGA_MAGENTA 5
#define VGA_BROWN 6
#define VGA_LIGHT_GRAY 7
#define VGA_DARK_GRAY 8
#define VGA_LIGHT_BLUE 9
#define VGA_LIGHT_GREEN 10
#define VGA_LIGHT_CYAN 11
#define VGA_LIGHT_RED 12
#define VGA_PINK 13
#define VGA_YELLOW 14
#define VGA_WHITE 15

#define VGA_CTRL_REGISTER 0x3d4
#define VGA_DATA_REGISTER 0x3d5
#define VGA_OFFSET_LOW 0x0f
#define VGA_OFFSET_HIGH 0x0e
#define VGA_VIDEO_ADDRESS 0xb8000
#define VGA_ROWS 25
#define VGA_COLS 80

void VGA_clear_screen();
void VGA_put_char(char c, uint8_t color, uint32_t pos);

void VGA_set_cursor(int offset);
int VGA_get_cursor();

uint8_t gen_color(uint8_t fg, uint8_t bg);

#endif // VGA_TEXT_H_

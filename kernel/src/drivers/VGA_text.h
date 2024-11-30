#ifndef VGA_TEXT_H_
#define VGA_TEXT_H_

#include <stdint.h>
#include <stddef.h>

#define VGA_CTRL_REGISTER 0x3d4
#define VGA_DATA_REGISTER 0x3d5
#define VGA_OFFSET_LOW 0x0f
#define VGA_OFFSET_HIGH 0x0e
#define VGA_VIDEO_ADDRESS 0xb8000
#define VGA_ROWS 50
#define VGA_COLS 160

void putc(char c);
void puts (const char* s);
void set_color_byte(const uint8_t new_color);

void set_text_mode_80x25();

#endif // VGA_TEXT_H_

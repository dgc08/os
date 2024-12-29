#ifndef KEYBOARD_LAYOUTS_H_
#define KEYBOARD_LAYOUTS_H_

#include <lib.h>

char get_ascii_char(unsigned char key_code);
bool set_keyboard_layout(char idnt[2]);

#endif // KEYBOARD_LAYOUTS_H_

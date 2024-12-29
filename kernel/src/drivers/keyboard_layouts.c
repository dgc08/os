#include <stdint.h>

#include "keyboard_layouts.h"
#include "keyboard_hardware.h"

#include "layouts.h"

bool set_keyboard_layout (char idnt[2]) {
    if (idnt[0] == 'd' && idnt[1] == 'e') {
        layout = keyboard_map_de;
    }
    else if (idnt[0] == 'e' && idnt[1] == 'n') {
        layout = keyboard_map_en;
    }
    else {
      return false;
    }
    return true;
}

char get_ascii_char (uint8_t key_code) {
    if (check_key(KEY_SHIFT))
        return layout.shift[key_code];

    return layout.normal[key_code];
}


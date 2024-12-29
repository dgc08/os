#include "keyboard_hardware.h"

#include <drivers/tty.h>

#include <iolib.h>
#include <stdint.h>

bool pressed_map[128];
Queue key_queue;

bool check_key (uint8_t code) {
    return pressed_map[code];
}

char get_keycode () {
    uint8_t code = inb(KEYBOARD_PORT);
    if (code & 128) {
        pressed_map[code & 127] = false;
    }
    else if (pressed_map[code & 127]) { } // key is already pressed
    else { //new key is pressed
        pressed_map[code & 127] = true;
        queue_enqueue(&key_queue, code);
    }
    return code;
}

#ifndef LAYOUTS_H_
#define LAYOUTS_H_

typedef struct {
    char normal[128];
    char shift[128];
    char alt_gr[128];
    char alt_gr_shift[128];
} KeyboardLayout;

KeyboardLayout layout = {
    .normal = {
        0,  27, '1', '2', '3', '4', '5', '6', '7', '8',     /* 9 */
      '9', '0', '-', '=', '\b',     /* Backspace */
      '\t',                 /* Tab */
      'q', 'w', 'e', 'r',   /* 19 */
      't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', /* Enter key */
        0,                  /* 29   - Control */
      'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',     /* 39 */
     '\'', '`',   0,                /* Left shift */
     '\\', 'z', 'x', 'c', 'v', 'b', 'n',                    /* 49 */
      'm', ',', '.', '/',   0,                              /* Right shift */
      '*',
        0,  /* Alt */
      ' ',  /* Space bar */
        0,  /* Caps lock */
        0,  /* 59 - F1 key ... > */
        0,   0,   0,   0,   0,   0,   0,   0,
        0,  /* < ... F10 */
        0,  /* 69 - Num lock*/
        0,  /* Scroll Lock */
        0,  /* Home key */
        0,  /* Up Arrow */
        0,  /* Page Up */
      '-',
        0,  /* Left Arrow */
        0,
        0,  /* Right Arrow */
      '+',
        0,  /* 79 - End key*/
        0,  /* Down Arrow */
        0,  /* Page Down */
        0,  /* Insert Key */
        0,  /* Delete Key */
        0,   0,   0,
        0,  /* F11 Key */
        0,  /* F12 Key */
        0,  /* All other keys are undefined */
    },
};

KeyboardLayout keyboard_map_en = {
    .normal = {
        0,  27, '1', '2', '3', '4', '5', '6', '7', '8',     /* 9 */
      '9', '0', '-', '=', '\b',     /* Backspace */
      '\t',                 /* Tab */
      'q', 'w', 'e', 'r',   /* 19 */
      't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', /* Enter key */
        0,                  /* 29   - Control */
      'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',     /* 39 */
     '\'', '`',   0,                /* Left shift */
     '\\', 'z', 'x', 'c', 'v', 'b', 'n',                    /* 49 */
      'm', ',', '.', '/',   0,                              /* Right shift */
      '*',
        0,  /* Alt */
      ' ',  /* Space bar */
        0,  /* Caps lock */
        0,  /* 59 - F1 key ... > */
        0,   0,   0,   0,   0,   0,   0,   0,
        0,  /* < ... F10 */
        0,  /* 69 - Num lock*/
        0,  /* Scroll Lock */
        0,  /* Home key */
        0,  /* Up Arrow */
        0,  /* Page Up */
      '-',
        0,  /* Left Arrow */
        0,
        0,  /* Right Arrow */
      '+',
        0,  /* 79 - End key*/
        0,  /* Down Arrow */
        0,  /* Page Down */
        0,  /* Insert Key */
        0,  /* Delete Key */
        0,   0,   0,
        0,  /* F11 Key */
        0,  /* F12 Key */
        0,  /* All other keys are undefined */
    },
};

KeyboardLayout keyboard_map_de = {
    .normal = {
        0,  27, '1', '2', '3', '4', '5', '6', '7', '8',     /* 9 */
      '9', '0', 's', '`', '\b',     /* Backspace */
      '\t',                 /* Tab */
      'q', 'w', 'e', 'r',   /* 19 */
      't', 'z', 'u', 'i', 'o', 'p', 'u', '+', '\n', /* Enter key */
        0,                  /* 29   - Control */
      'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'o',     /* 39 */
     'a', '^',   0,                /* Left shift */
     '#', 'y', 'x', 'c', 'v', 'b', 'n',                    /* 49 */
      'm', ',', '.', '-',   0,                              /* Right shift */
      0,
        0,  /* Alt: 56 */
      ' ',  /* Space bar */
        0,  /* Caps lock */
        0,  /* 59 - F1 key ... > */
        0,   0,   0,   0,   0,   0,   0,   0,
        0,  /* < ... F10 */
        0,  /* 69 - Num lock*/
        0,  /* Scroll Lock */
        0,  /* Home key */
        0,  /* Up Arrow */
        0,  /* Page Up */
      '-',
        0,  /* Left Arrow */
        0,
        0,  /* Right Arrow */
      '+',
        0,  /* 79 - End key*/
        0,  /* Down Arrow */
        0,  /* Page Down */
        0,  /* Insert Key */
        0,  /* Delete Key */
        0,   0,   '<',
        0,  /* F11 Key */
        0,  /* F12 Key */
        0,  /* All other keys are undefined */
    },
    .shift = {
        0,  27, '!', '"', 0, '$', '%', '&', '/', '(',     /* 9 */
      ')', '=', '?', 0, '\b',     /* Backspace */
      '\t',                 /* Tab */
      'Q', 'W', 'E', 'R',   /* 19 */
      'T', 'Z', 'U', 'I', 'O', 'P', 'U', '*', '\n', /* ENTER KEY */
        0,                  /* 29   - CONTROL */
      'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'O',     /* 39 */
     'A', 0,   0,                /* Left shift */
     '\'', 'Y', 'X', 'C', 'V', 'B', 'N',                    /* 49 */
      'M', ';', ':', '_',   0,                              /* Right shift */
      0,
        0,  /* Alt */
      ' ',  /* Space bar */
        0,  /* Caps lock */
        0,  /* 59 - F1 key ... > */
        0,   0,   0,   0,   0,   0,   0,   0,
        0,  /* < ... F10 */
        0,  /* 69 - Num lock*/
        0,  /* Scroll Lock */
        0,  /* Home key */
        0,  /* Up Arrow */
        0,  /* Page Up */
      '-',
        0,  /* Left Arrow */
        0,
        0,  /* Right Arrow */
      '+',
        0,  /* 79 - End key*/
        0,  /* Down Arrow */
        0,  /* Page Down */
        0,  /* Insert Key */
        0,  /* Delete Key */
        0,   0,   '>',
        0,  /* F11 Key */
        0,  /* F12 Key */
        0,  /* All other keys are undefined */
    }
};


#endif // LAYOUTS_H_

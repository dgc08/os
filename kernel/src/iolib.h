#ifndef IOLIB_H_
#define IOLIB_H_
#include <stdint.h>

void outb(uint16_t port, uint8_t data);
uint8_t inb(uint16_t port);

static inline void hlt_pause (void) {
    asm ("hlt");
}

__attribute__((noreturn))
static inline void hcf (void) {
    while (1) {
        hlt_pause();
    }
}

#endif // IOLIB_H_

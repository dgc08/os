#include <lib.h>

void dbbreak(void) {
    __asm__ volatile ("nop");
}

#include <lib.h>

__attribute__((noinline))
void dbbreak(void) {
    __asm__ volatile ("");
}

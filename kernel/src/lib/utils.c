#include <lib.h>
#include <stdint.h>

__attribute__((noinline))
void dbbreak(void) {
    __asm__ volatile ("");
}

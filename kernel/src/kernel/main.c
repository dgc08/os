#include "../lib.h"

void kmain(void) {
    asm volatile (
        "mov dword ptr [0xb8000], 0x2f4b2f4f\n"
        "mov dword ptr [0xb8004], 0x2f702f70\n"
    );
    while (1) {
        hcf();
    }
}

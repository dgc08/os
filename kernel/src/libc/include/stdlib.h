#ifndef _STDLIB_H
#define _STDLIB_H 1

#include "stddef.h"

#ifdef __cplusplus
extern "C" {
#endif

char* itoa (int value, char* str, int base);
char* utoa (unsigned value, char *str, int base);

#ifdef __cplusplus
}
#endif

#endif

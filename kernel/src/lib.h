#ifndef LIB_H_
#define LIB_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

void *memcpy(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);
void *memmove(void *dest, const void *src, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);

void dbbreak(void);

char* itoa(int value, char* str, int base);

#endif // LIB_H_

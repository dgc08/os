#ifndef LIB_H_
#define LIB_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

typedef uint8_t u8;
typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;

typedef struct {
    int x;
    int y;
} Vector2;

void *memcpy(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);
void *memmove(void *dest, const void *src, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);

void dbbreak(void);

__attribute__((noreturn))
void kernel_panic(int code, char* msg);

#endif // LIB_H_

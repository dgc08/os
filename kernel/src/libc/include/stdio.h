#ifndef _STDIO_H
#define _STDIO_H 1

#include <sys/cdefs.h>
#include <drivers/tty.h>

#define EOF (-1)

#ifdef __cplusplus
extern "C" {
#endif

int printf(const char* __restrict, ...);

#ifdef __cplusplus
}
#endif

#endif

#ifndef IOLIB_H_
#define IOLIB_H_

void outb(unsigned short port, unsigned char data);
unsigned char inb(unsigned short port);

static inline void hlt_pause(void) {
    asm ("hlt");
}

#endif // IOLIB_H_

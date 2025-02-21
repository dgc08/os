#include <drivers/tty.h>
#include <drivers/keyboard_hardware.h>
#include <lib.h>
#include <iolib.h>

#include <stdint.h>
#include <stdio.h>

#include <se-sh/se-target.h>
#include <se-sh/se-sh.h>

volatile int exit_code;
Terminal target_terminal;

char input_buffer[256];

void target_print (const char* str) {
    puts(str);
}

void target_write_output (const char* bytes, size_t nbytes) {
    tty_write(bytes, nbytes);
}


void target_print_int (int num) {
    printf("%d", num);
}

void poweroff(void); // in main.c
void target_exit (int code) {
    UNUSED(code);
    poweroff();
}

void target_newline () {
    putc('\n');
}

void target_sleep(uint32_t mills) {
    uint32_t iterations = mills * 3900 * 100; // Adjust for your CPU's MHz frequency

    asm volatile (
        "1: \n\t"               // Label for the loop
        "dec %[count] \n\t"     // Decrement the counter
        "jnz 1b \n\t"           // Jump back to label 1 if not zero
        : [count] "+r" (iterations) // Input and output operand
        : // No other inputs
        : "cc" // Clobbers condition flags
    );
}

int target_shell () {
    target_terminal.echo = true;
    while (1) {
        if (target_terminal.echo)
            printf("$ ");

        tty_read(input_buffer, 256, stdin);

        if (strlen(input_buffer) > 0) {
            int code = prompt(input_buffer);
            if (code < 0) {
                return (code+1)*-1;
            }
        }

    }

    return 0;
}

int target_system(char* command) {
    UNUSED(command);
    return 1;
}

void target_check_exit_condition() {}

void *malloc(size_t) {
    puts("Error: Unimplemented memory allocator\n");
    return 0;
}
void *realloc(void *, size_t){
    puts("Error: Unimplemented memory allocator\n");
    return 0;
}
void free(void *){
    puts("Error: Unimplemented memory allocator\n");
}

size_t target_write_file(const char*, Container) {
    puts("Error: Unimplemented file system\n");
    return 0;
}
Container target_read_file(const char*) {
    puts("Error: Unimplemented file system\n");
    return (Container){0,0};
}
Container target_list_files() {
    puts("Error: Unimplemented file system\n");
    return (Container){0,0};
}
bool target_remove_file(const char*) {
    puts("Error: Unimplemented file system\n");
    return 0;
}

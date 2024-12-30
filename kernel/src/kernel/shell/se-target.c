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

void target_sleep (uint32_t mills) {
    UNUSED(mills);
    kernel_panic(1, "sleep not implemented yet");
}

void get_input () {
    size_t i = 0;
    char ch = 0;
    input_buffer[0] = 0;
    while (ch != '\n') {
        if (ch == '\b' && i > 0) {
            putc(ch);
            i--;
        }
        else if (ch) {
            putc(ch);
            input_buffer[i] = ch;
            i++;
        }
        get_keycode();
        ch = getch();
    }

    input_buffer[i] = 0;
    putc('\n');
}

int target_shell () {
    target_terminal.echo = true;
    while (1) {
        if (target_terminal.echo)
            printf("$ ");

        get_input();

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
    kernel_panic(144, "Unimplemented memory allocator");
}
void *realloc(void *, size_t){
    kernel_panic(144, "Unimplemented memory allocator");
}
void free(void *){
    kernel_panic(144, "Unimplemented memory allocator");
}

size_t target_write_file(const char*, Container) {
    kernel_panic(144, "Unimplemented file system");
}
Container target_read_file(const char*) {
    kernel_panic(144, "Unimplemented file system");
}
Container target_list_files() {
    kernel_panic(144, "Unimplemented file system");
}
bool target_remove_file(const char*) {
    kernel_panic(144, "Unimplemented file system");
}

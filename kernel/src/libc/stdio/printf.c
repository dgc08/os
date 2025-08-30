#include <limits.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include <drivers/tty.h>

static bool print (const char* data, size_t length) {
	const unsigned char* bytes = (const unsigned char*) data;
	for (size_t i = 0; i < length; i++)
		if (putc(bytes[i]) == EOF)
			return false;
	return true;
}

int printf (const char* restrict format, ...) {
	va_list parameters;
	va_start(parameters, format);

	int written = 0;

	while (*format != '\0') {
		size_t maxrem = INT_MAX - written;

		if (format[0] != '%' || format[1] == '%') {
			if (format[0] == '%')
				format++;
			size_t amount = 1;
			while (format[amount] && format[amount] != '%')
				amount++;
			if (maxrem < amount) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(format, amount))
				return -1;
			format += amount;
			written += amount;
			continue;
		}

		const char* format_begun_at = format++;

		if (*format == 'c') {
			format++;
			char c = (char) va_arg(parameters, int /* char promotes to int */);
			if (!maxrem) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(&c, sizeof(c)))
				return -1;
			written++;
		} else if (*format == 's') {
			format++;
			const char* str = va_arg(parameters, const char*);
			size_t len = strlen(str);
			if (maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(str, len))
				return -1;
			written += len;
		} else if (*format == 'd') {
			format++;
			int value = va_arg(parameters, int); // Retrieve the next argument as an integer
			char buffer[12]; // Enough space to hold the largest 32-bit integer value as a string (+null terminator)
			itoa(value, buffer, 10); // Convert the integer to a decimal string
			size_t len = strlen(buffer); // Calculate the string length
			if (maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(buffer, len)) {
				return -1;
			}
			written += len;
		} else if (*format == 'u') {
			format++;
			int value = va_arg(parameters, unsigned int); // Retrieve the next argument as an integer
			char buffer[12]; // Enough space to hold the largest 32-bit integer value as a string (+null terminator)
			utoa(value, buffer, 16); // Convert the integer to a decimal string
			size_t len = strlen(buffer); // Calculate the string length
			if (maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(buffer, len)) {
				return -1;
			}
			written += len;
		} else if (*format == 'p') {
			format++;
			size_t value = va_arg(parameters, size_t); // Retrieve the next argument as an integer
			char buffer1[9]; // u32 in hex (+null terminator)
			char buffer2[9]; // u32 in hex (+null terminator)
			utoa(value>>32, buffer1, 16); // Convert the higher parts of the pointer to a hex string
			utoa(value & 0xFFFFFFFF, buffer2, 16); // Convert the lower parts of the pointer to a hex string

			char buffer_whole[17];
			int len1 = strlen(buffer1);
			int len2 = strlen(buffer2);
			for (int i = 0; i < 8-len1; i++) {
				buffer_whole[i] = '0';
			}
			memcpy(buffer_whole+8-len1, buffer1, len1);
			for (int i = 0; i < 8-len2; i++) {
				buffer_whole[i+8] = '0';
			}
			memcpy(buffer_whole+16-len2, buffer2, len2);

			size_t len = 17;
			if (maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(buffer_whole, len)) {
				return -1;
			}
			written += len;
		} else {
			format = format_begun_at;
			size_t len = strlen(format);
			if (maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(format, len))
				return -1;
			written += len;
			format += len;
		}
	}

	va_end(parameters);
	return written;
}

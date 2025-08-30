#include <stdlib.h>

char* itoa (int value, char* str, int base) {
    char* ret;
    char* ptr;
    char* low;
    // Check for supported base.
    if (base < 2 || base > 36) {
        *str = '\0';
        return str;
    }
    ret = ptr = str;
    // Set '-' for negative decimals.
    if (value < 0 && base == 10) {
        *ptr++ = '-';
    }
    // Remember where the numbers start.
    low = ptr;
    // The actual conversion.
    do {
        // Modulo is negative for negative value. This trick makes abs() unnecessary.
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"[35 + value % base];
        value /= base;
    } while (value);
    // Terminating the string.
    *ptr-- = '\0';
    // Invert the numbers.
    while (low < ptr) {
        char tmp = *low;
        *low++ = *ptr;
        *ptr-- = tmp;
    }
    return ret;
}

char *
__utoa (unsigned value,
        char *str,
        int base)
{
  const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int i, j;
  unsigned remainder;
  char c;

  /* Check base is supported. */
  if ((base < 2) || (base > 36))
    {
      str[0] = '\0';
      return NULL;
    }

  /* Convert to string. Digits are in reverse order.  */
  i = 0;
  do
    {
      remainder = value % base;
      str[i++] = digits[remainder];
      value = value / base;
    } while (value != 0);
  str[i] = '\0';

  /* Reverse string.  */
  for (j = 0, i--; j < i; j++, i--)
    {
      c = str[j];
      str[j] = str[i];
      str[i] = c;
    }

  return str;
}

char *
utoa (unsigned value,
        char *str,
        int base)
{
  return __utoa (value, str, base);
}

#ifndef _STDLIB_H
#define _STDLIB_H 1


#ifdef __cplusplus
extern "C" {
#endif

char* itoa (int value, char* str, int base);
int atoi(const char *num);

int isblank(int c);
int isspace(int c);
int islower(int c);
int isupper(int c);
int isdigit(int c);
int isalpha(int c);
int isalnum(int c);
int isxdigit(int c);
int isgraph(int c);
int iscntrl(int c);
int isprint(int c);
int ispunct(int c);
int tolower(int c);
int toupper(int c);


#ifdef __cplusplus
}
#endif

#endif

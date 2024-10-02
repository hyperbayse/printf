#ifndef _PRINTF
#define _PRINTF

#define BUFFER 1024

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int _strlen(char *s);
char *increase_buffer_size(char *old_buffer, int *buffer_count);
void case_s(char *s, char **output, int *buffer_count, unsigned int *oi);
int case_default(const char *format, int x, char *output, unsigned int *i);

#endif /* _PRINTF */
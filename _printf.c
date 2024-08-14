#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * _printf - prints to the standard output
 * @format: select which format to be used
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int x, i, j;
	char c;
	char *s, *output;
	va_list arg_p;

	i = x = j = 0;

	output = malloc(10 * sizeof(char));
	if (!(output))
		return (1);
	va_start(arg_p, format);
	while (format[x] != '\0')
	{
		if (format[x] == '%')
		{
			x++;
			switch (format[x])
			{
			case 'c':
				c = va_arg(arg_p, int);
				output[i++] = c;
				break;
			case 's':
				s = va_arg(arg_p, char *);
				while (s[j] != '\0')
					output[i++] = s[j++];
				break;
			default:
				break;
			}
			j = 0;
		}
		else
			output[i++] = format[x];
		x++;
	}
	va_end(arg_p);
	return (write(1, output, i));
	free(output);
}

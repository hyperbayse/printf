#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int _printf(const char *format, ...)
{
	int x, i, j;
	char c;
	char *s;
	char *output;
	va_list arg_p;

	i = x = j = 0;

	output = malloc(10 * sizeof(char));
	if (output == NULL)
		return (1);

	va_start(arg_p, format);
	while (format[x] != '\0')
	{
		/* checks for format specifier */
		if (format[x] == '%')
		{
			x++;
			switch (format[x])
			{
			case 'c' :
				c = va_arg(arg_p, int);
				output[i++] = c;
				break;
			case 's' :
				s = va_arg(arg_p, char *);
				while (s[j] != '\0')
					output[i++] = s[j++];
				break;
			default:
				break;
			}
			j = 0;
		}
		/* copies information from format to output */
		else
		{
			output[i] = format[x];
			i++;
		}
		x++;
	}
	va_end(arg_p);

	/* print the stored strings to the standard output */
	write(1, output, i);
	free(output);
	return (i);
}

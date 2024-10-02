#include "main.h"

/**
 * _printf - prints to the standard output
 * @format: select which format to be used
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	unsigned int x, i, j;
	int buffer_count = 1;
	char c;
	char *s, *output;
	va_list arg_p;

	i = x = j = 0;
	if (format == NULL)
		return (-1);
	output = malloc(BUFFER);
	if (output == NULL)
		return (2);
	va_start(arg_p, format);
	while (format[x] != '\0')
	{
		if (_strlen(output) == (BUFFER * buffer_count) - 1)
			output = increase_buffer_size(output, buffer_count);
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
				case_s(s, output, buffer_count, i, j);
				break;
			default:
				case_default(format, x, output, i);
			}
			j = 0;
		}
		else
			output[i++] = format[x];
		x++;
	}
	va_end(arg_p);
	write(1, output, i);
	free(output);
	return (i);
}

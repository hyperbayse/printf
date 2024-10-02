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
		return (1);

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

				if (s == NULL)
				{
					s = "(null)";
				}

				/**
				* check if the lenght of string argument is more than
				* the remaining space in the allocated buffer
				* if yes, increase the buffer size
				*/
				if (_strlen(s) > (BUFFER * buffer_count) - _strlen(output))
					output = increase_buffer_size(output, buffer_count);

				while (s[j] != '\0')
					output[i++] = s[j++];
				break;
			default:
				if (format[x] == '%')
					output[i++] = format[x];
				else if (format[x] == '\0')
					break;
				else
				{
					if (format[x] != '\0')
					{
						output[i++] = format[x - 1];
						output[i++] = format[x];
						break;
					}
				}
				/*return (0);*/
				/*output[i++] = format[x];*/
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

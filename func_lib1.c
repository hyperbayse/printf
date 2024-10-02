#include "main.h"

/**
 * _strlen - caluclates the lenght of a string
 * @s: string parsed
 * Return: lenght
 */

int _strlen(char *s)
{
	unsigned int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * increase_buffer_size - increases the initially allocated space
 * and copy the old content to it
 * @old_buffer: the old buffer parsed
 * @buffer_count: number of times the memry is being incremented
 * Return: new_buffer on success and NULL otherwise
 */

char *increase_buffer_size(char *old_buffer, int *buffer_count)
{
	int i = 0;
	char *new_buffer;

	(*buffer_count)++;

	new_buffer = malloc(BUFFER * (*buffer_count));

	if (new_buffer == NULL)
		return (NULL);

	while (old_buffer[i] != '\0')
	{
		new_buffer[i] = old_buffer[i];
		i++;
	}
	free(old_buffer);
	return (new_buffer);
}

/**
 * case_s - handle the case of a string in _printf function
 * @s: the string argument
 * @output: where the string will be cached to
 * @buffer_count: number of times buffer is be incremented
 * @oi: output iterator
 * Return: success
 */

void case_s(char *s, char **output, int *buffer_count, unsigned int *oi)
{
	int si = 0;

	if (s == NULL)
		s = "(null)";

	if (_strlen(s) > (BUFFER * (*buffer_count)) - _strlen(*output))
	{
		*output = increase_buffer_size(*output, buffer_count);
		if (*output == NULL)
			return;
	}

	while (s[si] != '\0')
		(*output)[(*oi)++] = s[(si)++];
}

/**
 * case_default - handle the case when no formate is matched
 * @format: format parsed
 * @x: format interator
 * @output: output buffer
 * @i: output iterator
 * Return: success
 */

int case_default(const char *format, int x, char *output, unsigned int *i)
{
	if (format[x] == '\0')
		return (-1);

	if (format[x] == '%')
		output[*i++] = format[x];
	else
	{
		output[*i++] = format[x - 1];
		output[*i++] = format[x];
	}
	return (0);
}

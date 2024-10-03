#include "main.h"

/**
 * case_di - handles the case of d or i for integers
 * @output: the output buffer
 * @i: output iterator
 * @number: argument value
 * Return: success
 */

void case_di(char *output, unsigned int *i, int number)
{
	int x = number, j = 0;
	char *temp = malloc(32);

	if (temp == NULL)
		return;

	while (x > 0)
	{
		temp[j] = (x % 10) + 48;
		x = x / 10;
		j++;
	}

	j = _strlen(temp);

	while (j >= 0)
		output[(*i)++] = temp[--j];

	free(temp);
	(*i)--;
}

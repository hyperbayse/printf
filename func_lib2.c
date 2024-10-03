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
	long int x = number, j = 0;
	char *temp = malloc(64);

	if (temp == NULL)
		return;

	if (x < 0)
		x = x * (-1);
	if (x == 0)
	{
		temp[j] = '0';
		j++;
	}

	while (x > 0)
	{
		temp[j] = (x % 10) + 48;
		x = x / 10;
		j++;
	}

	if (number < 0)
	{
		temp[j] = '-';
		j++;
	}

	j = _strlen(temp);

	while (j >= 0)
		output[(*i)++] = temp[--j];

	free(temp);
	(*i)--;
}

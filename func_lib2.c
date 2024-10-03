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
		temp[j++] = '0';

	while (x > 0)
	{
		temp[j++] = (x % 10) + 48;
		x = x / 10;
	}

	if (number < 0)
		temp[j++] = '-';

	j = _strlen(temp);

	while (j >= 0)
		output[(*i)++] = temp[--j];

	free(temp);
	(*i)--;
}


/**
 * case_b - handle the binary format specifier
 * @output: output buffer
 * @i: output iterator
 * @binary_value: the binary value to be converted
 * Return: success
 */

void case_b(char *output, unsigned int *i, unsigned int binary_value)
{
	unsigned int b = binary_value, j = 0, zero = 0;
	char *temp = malloc(65);

	if (temp == NULL)
		return;

	if (b == 0)
		temp[j++] = '0';

	while (b > zero)
	{
		temp[j++] = (b % 2) + 48;
		b = b / 2;
	}

	while (j > zero)
		output[(*i)++] = temp[--j];
	output[(*i)++] = temp[0];

	free(temp);
	(*i)--;
}

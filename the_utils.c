#include "main.h"

/**
 * it_is_printable - evaluatess if a char is printable
 * @r: char to be evaluated
 *
 * Return: 1 if r is printable, 0 otherwise
 */

int it_is_printable(char r)
{
	if (r >= 32 && r < 127)
		return (1);

	return (0);
}

/**
 * append_the_hexa_code - append assci in hexadecimal code to buffer
 * @buffer: array of chars
 * @y: index at which to start appending
 * @ascii_code: ASSCI CODE
 * Return: Always 3
 */

int append_the_hexa_code(char ascii_code, char buffer[], int y)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is  always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[y++] = '\\';
	buffer[y++] = 'x';

	buffer[y++] = map_to[ascii_code / 16];
	buffer[y] = map_to[ascii_code % 16];

	return (3);
}

/**
 * it_is_digit - verifies if a char is a digit
 * @r: char to be evaluated
 *
 * Return: 1 if r is a digit, 0 otherwise
 */

int it_is_digit(char r)
{
	if (r >= '0' && r <= '9')
		return (1);

	return (0);
}

/**
 * convert_the_size_number - casts a number to the specified size
 * @num: number to be casted
 * @size: number indicating the type to be casted
 *
 * Return: casted value of num
 */

long int convert_the_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_the_size_unsgnd - casts a number to the specified size
 * @num: number to be casted
 * @size: number indicating the type to be casted
 *
 * Return: casted value of num
 */

long int convert_the_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

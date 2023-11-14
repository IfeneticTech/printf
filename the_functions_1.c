#include "main.h"

/************************** PRINT UNSIGNED NUMBER *************************/

/**
 * print_the_unsigned - function that prints an unsigned number
 * @types_all: list a of arguments
 * @buffer: the buffer array to handle print
 * @flags: calculates the active flags
 * @width: get width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: number of chars printed
 */

int print_the_unsigned(va_list types_all, char buffer[],
	int flags, int width, int precision, int size)
{
	int y = BUFF_SIZE - 2;
	unsigned int num = va_arg(types_all, unsigned long int);

	num = convert_the_size_unsgnd(num, size);

	if (num == 0)
		buffer[y--] = '\0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[y--] = (num % 10) + '0';
		num /= 10;
	}

	y++;

	return (write_the_unsgnd(0, y, buffer, flags, width, precision, size));
}

/******************** PRINT UNSIGNED NUMBER IN OCTAL *******************/

/**
 * print_the_octal - function that prints an unsigned number in octal notation
 * @types_all: list a of arguments
 * @buffer: the buffer array to handle print
 * @flags: calculates the active flags
 * @width: get width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: number of chars printed
 */

int print_the_octal(va_list types_all, char buffer[],
	int flags, int width, int precision, int size)
{
	int y = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types_all, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_the_size_unsgnd(num, size);

	if (num == 0)
		buffer[y--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[y--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[y--] = '0';

	y++;

	return (write_the_unsgnd(0, y, buffer, flags, width, precision, size));
}

/***************** PRINT UNSIGNED NUMBER IN HEXADECIMAL *****************/

/**
 * print_the_hexadecimal - function that prints an
 * unsigned number in hexadecimal notation
 * @types_all: lista of arguments
 * @buffer: the buffer array to handle print
 * @flags: calculates the active flags
 * @width: get width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: number of chars printed
 */

int print_the_hexadecimal(va_list types_all, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_the_hexa(types_all, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/***************** PRINT UNSIGNED NUMBER IN HEXADECIMAL ****************/

/**
 * print_the_hexa_upper - function that prints an
 * unsigned number in upper hexadecimal notation
 * @types_all: lista of arguments
 * @buffer: the buffer array to handle print
 * @flags: calculates the active flags
 * @width: get width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: number of chars printed
 */

int print_the_hexa_upper(va_list types_all, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_the_hexa(types_all, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/

/**
 * print_the_hexa - prints a hexadecimal number in lower or upper
 * @types_all: lista of arguments
 * @map_to: array of values to map the number to
 * @buffer: the buffer array to handle print
 * @flags: calculates the active flags
 * @flag_ch: calculates the active flags
 * @width: get width
 * @precision: the precision specification
 * @size: the size specifier
 * @size: the size specification
 * Return: number of chars printed
 */

int print_the_hexa(va_list types_all, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int y = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types_all, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_the_size_unsgnd(num, size);

	if (num == 0)
		buffer[y--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[y--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[y--] = flag_ch;
		buffer[y--] = '0';
	}

	y++;

	return (write_the_unsgnd(0, y, buffer, flags, width, precision, size));
}

#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_the_char - function prints a char
 * @types_all: the listt a of arguments
 * @buffer: the buffer array to handle print
 * @flags: calculates the active flags
 * @width: get width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the number of chars printed
 */

int print_the_char(va_list types_all, char buffer[],
	int flags, int width, int precision, int size)
{
	char r = va_arg(types_all, int);

	return (handle_the_write_char(r, buffer, flags, width, precision, size));
}

/************************* PRINT A STRING *************************/

/**
 * print_the_string - function prints a string
 * @types_all: the lisst a of arguments
 * @buffer: the bufer array to handle print
 * @flags: calculates the active flags
 * @width: get width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the number of chars printed
 */
int print_the_string(va_list types_all, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, y;
	char *str = va_arg(types_all, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (y = width - length; y > 0; y--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (y = width - length; y > 0; y--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/************************* PRINT PERCENT SIGN *************************/

/**
 * print_the_percent - function that prints a percent sign
 * @types_all: lista of arguments
 * @buffer: the buffer array to handle print
 * @flags: calculates the active flags
 * @width: get width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the number of chars printed
 */
int print_the_percent(va_list types_all, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types_all);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/

/**
 * print_the_int - function that print int
 * @types_all: lista of arguments
 * @buffer: the buffer array to handle print
 * @flags: calculates the active flags
 * @width: get width
 * @precision: the precision specification
 * @size: the size specifier
 * Return: the number of chars printed
 */
int print_the_int(va_list types_all, char buffer[],
	int flags, int width, int precision, int size)
{
	int y = BUFF_SIZE - 2;
	int it_is_negative = 0;
	long int b = va_arg(types_all, long int);
	unsigned long int num;

	b = convert_the_size_number(b, size);

	if (b == 0)
		buffer[y--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)b;

	if (b < 0)
	{
		num = (unsigned long int)((-1) * b);
		it_is_negative = 1;
	}

	while (num > 0)
	{
		buffer[y--] = (num % 10) + '0';
		num /= 10;
	}

	y++;

	return (write_the_number(it_is_negative, y, buffer,
				flags, width, precision, size));
}

/************************** PRINT BINARY *************************/

/**
 * print_the_binary - function thatt prints an unsigned number
 * @types_all: lista of arguments
 * @buffer: the buffer array to handle print
 * @flags: calculates the active flags
 * @width: get width
 * @precision:  the precision specification
 * @size: the size specifier
 * Return: the number of chars printed
 */

int print_the_binary(va_list types_all, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int b, w, y, sum;
	unsigned int v[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	b = va_arg(types_all, unsigned int);
	w = 2147483648; /* (2 ^ 31) */
	v[0] = b / w;
	for (y = 1; y < 32; y++)
	{
		w /= 2;
		v[y] = (b / w) % 2;
	}
	for (y = 0, sum = 0, count = 0; y < 32; y++)
	{
		sum += v[y];
		if (sum || y == 31)
		{
			char z = '0' + v[y];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

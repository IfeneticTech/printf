#include "main.h"

/****************** PRINT POINTER ******************/

/**
 * print_the_pointer - prints the value of a pointer variable
 * @types_all: list a of arguments
 * @buffer: the buffer array to handle print
 * @flags: calculates the active flags
 * @width: get width
 * @precision: thhe precision specification
 * @size: the size specifier
 * Return: number of chars printed
 */

int print_the_pointer(va_list types_all, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_r = 0, paddd = ' ';
	int innd = BUFF_SIZE - 2, length = 2, paddd_start = 1;
	/* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types_all, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[innd--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		paddd = '0';
	if (flags & F_PLUS)
		extra_r = '+', length++;
	else if (flags & F_SPACE)
		extra_r = ' ', length++;

	innd++;

	/* return (write(1, &buffer[y], BUFF_SIZE - y - 1));*/
	return (write_the_pointer(buffer, innd, length,
		width, flags, paddd, extra_r, paddd_start));
}

/****************** PRINT NON PRINTABLE ******************/

/**
 * print_the_non_printable - prints ascii codes in hexa of non printable chars
 * @types_all: lista of arguments
 * @buffer: the buffer array to handle print
 * @flags: calculates the active flags
 * @width: get width
 * @precision: thhe precision specification
 * @size: the size specifier
 * Return: number of chars printed
 */

int print_the_non_printable(va_list types_all, char buffer[],
	int flags, int width, int precision, int size)
{
	int y = 0, offset = 0;
	char *str = va_arg(types_all, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[y] != '\0')
	{
		if (it_is_printable(str[y]))
			buffer[y + offset] = str[y];
		else
			offset += append_the_hexa_code(str[y], buffer, y + offset);
		y++;
	}

	buffer[y + offset] = '\0';

	return (write(1, buffer, y + offset));
}

/****************** PRINT REVERSE ******************/

/**
 * print_the_reverse - prints reverse string
 * @types_all: lista of arguments
 * @buffer: the buffer array to handle print
 * @flags: calculates the active flags
 * @width: get width
 * @precision: thhe precision specification
 * @size: the size specifier
 * Return: number of chars printed
 */

int print_the_reverse(va_list types_all, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int y, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types_all, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (y = 0; str[y]; y++)
		;

	for (y = y - 1; y >= 0; y--)
	{
		char z = str[y];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/****************** PRINT A STRING IN ROT13 ******************/

/**
 * print_the_rot13string - function that prints a string in rot13
 * @types_all: lista of arguments
 * @buffer: the buffer array to handle print
 * @flags: calculates the active flags
 * @width: get width
 * @precision: thhe precision specification
 * @size: the size specifier
 * Return: number of chars printed
 */

int print_the_rot13string(va_list types_all, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int y, k;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types_all, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (y = 0; str[y]; y++)
	{
		for (k = 0; in[k]; k++)
		{
			if (in[k] == str[y])
			{
				x = out[k];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[k])
		{
			x = str[y];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}

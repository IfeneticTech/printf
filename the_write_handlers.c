#include "main.h"

/***************** WRITE HANDLE ******************/

/**
 * handle_the_write_char - prints a string
 * @r: the char types
 * @buffer: the buffer array to handle print
 * @flags: calculates the active flags
 * @width: get width
 * @precision: the precision specifier
 * @size: the size specifier
 *
 * Return: number of chars printed
 */

int handle_the_write_char(char r, char buffer[],
	int flags, int width, int precision, int size)
{ /* char is stored at left and paddind at buffer's right */
	int y = 0;
	char paddd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		paddd = '0';

	buffer[y++] = r;
	buffer[y] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (y = 0; y < width - 1; y++)
			buffer[BUFF_SIZE - y - 2] = paddd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - y - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - y - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/****************** WRITE NUMBER ******************/

/**
 * write_the_number - prints a string
 * @it_is_negative: lista of arguments
 * @innd: char types
 * @buffer: the buffer array to handle print
 * @flags: calculates the active flags
 * @width: get width
 * @precision: the precision specifier
 * @size: the size specifier
 *
 * Return: number of chars printed
 */

int write_the_number(int it_is_negative, int innd, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - innd - 1;
	char paddd = ' ', extra_r = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		paddd = '0';
	if (it_is_negative)
		extra_r = '-';
	else if (flags & F_PLUS)
		extra_r = '+';
	else if (flags & F_SPACE)
		extra_r = ' ';

	return (write_the_num(innd, buffer, flags, width, precision,
		length, paddd, extra_r));
}

/**
 * write_the_num - writes a number using a bufffer
 * @innd: the index at which the number starts on the buffer
 * @buffer: the buffer
 * @flags: the flags
 * @width: width
 * @prec: precision specifier
 * @length: number length
 * @paddd: pading char
 * @extra_r: extra char
 *
 * Return: number of printed chars
 */

int write_the_num(int innd, char buffer[],
	int flags, int width, int prec,
	int length, char paddd, char extra_r)
{
	int y, paddd_start = 1;

	if (prec == 0 && innd == BUFF_SIZE - 2 && buffer[innd] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && innd == BUFF_SIZE - 2 && buffer[innd] == '0')
		buffer[innd] = paddd = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < length)
		paddd = ' ';
	while (prec > length)
		buffer[--innd] = '0', length++;
	if (extra_r != 0)
		length++;
	if (width > length)
	{
		for (y = 1; y < width - length + 1; y++)
			buffer[y] = paddd;
		buffer[y] = '\0';
		if (flags & F_MINUS && paddd == ' ')/* Asign extra char to left of buffer */
		{
			if (extra_r)
				buffer[--innd] = extra_r;
			return (write(1, &buffer[innd], length) + write(1, &buffer[1], y - 1));
		}
		else if (!(flags & F_MINUS) && paddd == ' ')/* extra char to left of buff */
		{
			if (extra_r)
				buffer[--innd] = extra_r;
			return (write(1, &buffer[1], y - 1) + write(1, &buffer[innd], length));
		}
		else if (!(flags & F_MINUS) && paddd == '0')/* extra char to left of padd */
		{
			if (extra_r)
				buffer[--paddd_start] = extra_r;
			return (write(1, &buffer[paddd_start], y - paddd_start) +
				write(1, &buffer[innd], length - (1 - paddd_start)));
		}
	}
	if (extra_r)
		buffer[--innd] = extra_r;
	return (write(1, &buffer[innd], length));
}

/**
 * write_the_unsgnd - writes an unsigned number
 * @it_is_negative: number indicating if the num is negative
 * @innd: the index at which the number starts in the buffer
 * @buffer: array of chars
 * @flags: flags specifiers
 * @width: width specifier
 * @precision: the precision specifier
 * @size: the size specifier
 *
 * Return: number of written chars
 */
int write_the_unsgnd(int it_is_negative, int innd,
	char buffer[],
	int flags, int width, int precision, int size)
{
	/* The number is stored at the bufer's right and starts at position i */
	int length = BUFF_SIZE - innd - 1, y = 0;
	char paddd = ' ';

	UNUSED(it_is_negative);
	UNUSED(size);

	if (precision == 0 && innd == BUFF_SIZE - 2 && buffer[innd] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < length)
		paddd = ' ';

	while (precision > length)
	{
		buffer[--innd] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		paddd = '0';

	if (width > length)
	{
		for (y = 0; y < width - length; y++)
			buffer[y] = paddd;

		buffer[y] = '\0';

		if (flags & F_MINUS) /* Asign extra char to left of buffer [buffer>paddd]*/
		{
			return (write(1, &buffer[innd], length) + write(1, &buffer[0], y));
		}
		else /* Asign extra char to left of padding [paddd>buffer]*/
		{
			return (write(1, &buffer[0], y) + write(1, &buffer[innd], length));
		}
	}

	return (write(1, &buffer[innd], length));
}

/**
 * write_the_pointer - writes a memory address
 * @buffer: arrays of chars
 * @innd: index at which the number starts in the buffer
 * @length: the length of number
 * @width: width specifier
 * @flags: the flags specifier
 * @paddd: the char representing the padding
 * @extra_r: the char representing extra char
 * @paddd_start: index at which padding should start
 *
 * Return: number of written chars
 */
int write_the_pointer(char buffer[], int innd, int length,
	int width, int flags, char paddd, char extra_r, int paddd_start)
{
	int y;

	if (width > length)
	{
		for (y = 3; y < width - length + 3; y++)
			buffer[y] = paddd;
		buffer[y] = '\0';
		if (flags & F_MINUS && paddd == ' ')/* Asign extra char to left of buffer */
		{
			buffer[--innd] = 'x';
			buffer[--innd] = '0';
			if (extra_r)
				buffer[--innd] = extra_r;
			return (write(1, &buffer[innd], length) + write(1, &buffer[3], y - 3));
		}
		else if (!(flags & F_MINUS) && paddd == ' ')
			/* extra char to left of buffer */
		{
			buffer[--innd] = 'x';
			buffer[--innd] = '0';
			if (extra_r)
				buffer[--innd] = extra_r;
			return (write(1, &buffer[3], y - 3) + write(1, &buffer[innd], length));
		}
		else if (!(flags & F_MINUS) && paddd == '0')/* extra char to left of paddd */
		{
			if (extra_r)
				buffer[--paddd_start] = extra_r;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[paddd_start], y - paddd_start) +
				write(1, &buffer[innd], length - (1 - paddd_start) - 2));
		}
	}
	buffer[--innd] = 'x';
	buffer[--innd] = '0';
	if (extra_r)
		buffer[--innd] = extra_r;
	return (write(1, &buffer[innd], BUFF_SIZE - innd - 1));
}

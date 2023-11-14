#include "main.h"

void print_the_buffer(char buffer[], int *buff_innd);

/**
 * _printf - the printf function
 * @format: the format
 * Return: the printed chars
 */
int _printf(const char *format, ...)
{
	int y, printed = 0, printed_the_chars = 0;
	int flags, width, precision, size, buff_innd = 0;
	va_list list_all;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list_all, format);

	for (y = 0; format && format[y] != '\0'; y++)
	{
		if (format[y] != '%')
		{
			buffer[buff_innd++] = format[y];
			if (buff_innd == BUFF_SIZE)
				print_the_buffer(buffer, &buff_innd);
			/* write(1, &format[y], 1);*/
			printed_the_chars++;
		}
		else
		{
			print_the_buffer(buffer, &buff_innd);
			flags = get_the_flags(format, &y);
			width = get_the_width(format, &y, list_all);
			precision = get_the_precision(format, &y, list_all);
			size = get_the_size(format, &y);
			++y;
			printed = handle_the_print(format, &y, list_all, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_the_chars += printed;
		}
	}

	print_the_buffer(bufer, &buff_innd);

	va_end(list_all);

	return (printed_the_chars);
}

/**
 * print_the_buffer - function that prints the contents
 * of the buffer if it exist.
 * @buffer: the array of chars.
 * @buff_innd: index at which to add next char, that represents the length.
 */
void print_the_buffer(char buffer[], int *buff_innd)
{
	if (*buff_innd > 0)
		write(1, &buffer[0], *buff_innd);

	*buff_innd = 0;
}

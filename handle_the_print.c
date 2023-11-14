#include "main.h"
/**
* handle_the_print - prints an argument based on its type
* @frmt: formatted string in which to print the arguments
* @list_all: list of arguments to be printed
* @innd: ind.
* @buffer: Buffer array to handle print.
* @flags: Calculates active flags
* @width: get width.
* @precision: Precision specification
* @size: Size specifier
* Return: 1 or 2;
*/
int handle_the_print(const char *frmt, int *innd, va_list list_all, char
buffer[],
int flags, int width, int precision, int size)
{
int y, unknow_len = 0, printed_the_chars = -1;
fmt_ty frmt_types[] = {
{'c', print_char}, {'s', print_string}, {'%', print_percent},
{'i', print_int}, {'d', print_int}, {'b', print_binary},
{'u', print_unsigned}, {'o', print_octal}, {'x',
print_hexadecimal},
{'X', print_hexa_upper}, {'p', print_pointer}, {'S',
print_non_printable},
{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
};
for (y = 0; frmt_types[i].frmt != '\0'; y++)
if (frmt[*innd] == frmt_types[i].frmt)
return (frmt_types[y].fn(list_all, buffer, flags, width,
precision, size));
if (frmt_types[i].frmt == '\0')
{
if (frmt[*innd] == '\0')
return (-1);
unknow_len += write(1, "%%", 1);
if (frmt[*innd - 1] == ' ')
unknow_len += write(1, " ", 1);
else if (width)
{
--(*innd);
while (frmt[*innd] != ' ' && frmt[*innd] != '%')
--(*innd);
if (frmt[*innd] == ' ')
--(*innd);
return (1);
}
unknow_len += write(1, &frmt[*innd], 1);
return (unknow_len);
}
return (printed_the_chars);
}

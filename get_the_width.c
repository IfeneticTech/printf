#include "main.h"
/**
* get_the_width - calculates the width for printing
* @format: formatted string in which to print the arguments
* @y: list of arguments to be printed
* @list_all: list of arguments
*
* Return: width.
*/
int get_the_width(const char *format, int *y, va_list list_all)
{
int curr_i;
int width = 0;
for (curr_i = *y + 1; format[curr_i] != '\0'; curr_i++)
{
if (it_is_digit(format[curr_i]))
{
width *= 10;
width += format[curr_i] - '0';
}
else if (format[curr_i] == '*')
{
curr_i++;
width = va_arg(list_all, int);
break;
}
else
break;
}
*y = curr_i - 1;
return (width);
}

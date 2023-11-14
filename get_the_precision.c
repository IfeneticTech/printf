#include "main.h"
/**
* get_the_precision - calculates the precision for printing
* @format: Formatted string in which is to print the arguments
* @y: list of arguments to be printed.
* @list_all: the list of arguments.
*
* Return: precision.
*/
int get_the_precision(const char *format, int *y, va_list list_all)
{
int curr_i = *y + 1;
int precision = -1;
if (format[curr_i] != '.')
return (precision);
precision = 0;
for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
{
if (it_is_digit(format[curr_i]))
{
precision *= 10;
precision += format[curr_i] - '0';
}
else if (format[curr_i] == '*')
{
curr_i++;
precision = va_arg(list_all, int);
break;
}
else
break;
}
*y = curr_i - 1;
return (precision);
}

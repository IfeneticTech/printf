#include "main.h"
/**
* get_the_size - calculates the size to cast the argument
* @format: formatted string in which to print the arguments
* @y: list of arguments to be printed
*
* Return: Precision
*/
int get_the_size(const char *format, int *y)
{
int curr_i = *y + 1;
int size = 0;
if (format[curr_i] == 'l')
size = S_LONG;
else if (format[curr_i] == 'h')
size = S_SHORT;
if (size == 0)
*y = curr_i - 1;
else
*y = curr_i;
return (size);
}

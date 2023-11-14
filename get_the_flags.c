#include "main.h"
/**
* get_the_flags - calculates the active flags
* @format: formatted string in which to print the arguments
* @y: take a parameter.
* Return: flags:
*/
int get_the_flags(const char *format, int *y)
{
/* - + 0 # ' ' */
/* 1 2 4 8 16 */
int k, curr_i;
int flags = 0;
const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
for (curr_i = *y + 1; format[curr_i] != '\0'; curr_i++)
{
for (k = 0; FLAGS_CH[k] != '\0'; k++)
if (format[curr_i] == FLAGS_CH[k])
{
flags |= FLAGS_ARR[k];
break;
}
if (FLAGS_CH[k] == 0)
break;
}
*y = curr_i - 1;
return (flags);
}

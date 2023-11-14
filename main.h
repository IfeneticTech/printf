#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct frmt - the struct op
 *
 * @frmt: the format.
 * @fnn: the associated function.
 */
struct frmt
{
	char frmt;
	int (*fnn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct frmt fmt_ty - Struct op
 *
 * @frmt: the format.
 * @fmt_ty: the associated function
 */
typedef struct frmt fmt_ty;

int _printf(const char *format, ...);
int handle_the_print(const char *frmt, int *y,
		va_list list_all, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Functions to print chars and  strings */
int print_the_char(va_list types_all, char buffer[],
	int flags, int width, int precision, int size);
int print_the_string(va_list types_all, char buffer[],
	int flags, int width, int precision, int size);
int print_the_percent(va_list types_all, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_the_int(va_list types_all, char buffer[],
	int flags, int width, int precision, int size);
int print_the_binary(va_list types_all, char buffer[],
	int flags, int width, int precision, int size);
int print_the_unsigned(va_list types_all, char buffer[],
	int flags, int width, int precision, int size);
int print_the_octal(va_list types_all, char buffer[],
	int flags, int width, int precision, int size);
int print_the_hexadecimal(va_list types_all, char buffer[],
	int flags, int width, int precision, int size);
int print_the_hexa_upper(va_list types_all, char buffer[],
	int flags, int width, int precision, int size);

int print_the_hexa(va_list types_all, char map_to[],
		char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_the_non_printable(va_list types_all, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print memory address */
int print_the_pointer(va_list types_all, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int get_the_flags(const char *format, int *y);
int get_the_width(const char *format, int *y, va_list list_all);
int get_the_precision(const char *format, int *y, va_list list_all);
int get_the_size(const char *format, int *y);

/* Function to print string in reverse */
int print_the_rot13string(va_list types_all, char buffer[],
	int flags, int width, int precision, int size);

/* Width handler */
int handle_the_write_char(char r, char buffer[],
	int flags, int width, int precision, int size);
int write_the_number(int it_is_positive, int innd, char buffer[],
	int flags, int width, int precision, int size);
int write_the_num(int innd, char bff[], int flags, int width, int precision,
	int length, char paddd, char extra_r);
int write_the_pointer(char buffer[], int innd, int length,
	int width, int flags, char paddd, char extra_r, int paddd_start);

int write_the_unsgnd(int it_is_negative, int innd,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int it_is_printable(char);
int append_the_hexa_code(char, char[], int);
int it_is_digit(char);

long int convert_the_size_number(long int num, int size);
long int convert_the_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */

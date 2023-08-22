#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#define UNUTILIZED(x) (void)(x)
#define BUFF_SIZE 1024
/* SIZES */
#define S_SHORT 1
#define S_LONG 2
/* FLAGS */
#define F_SPACE 16
#define F_ZERO 4
#define F_HASH 8
#define F_MINUS 1
#define F_PLUS 2
/**
 * struct fom - struct op
 * @fom: the format
 * @func: the corresponding function
 */
struct fom
{
char fom;
int (*func)(va_list, char[], int, int, int, int);
};
/**
 * typedef struct fom fom_t - struct op
 * @fom: the format
 * @fom_t: the corresponding function
 */
typedef sturct fom fom_t;
int _printf(const char *format, ...);
int handle_print(const char *fom, int *j, va_list list, char buffer[],
int flags, int width, int precision, int size);
/* functions that print chars and strings */
int print_char(va_list types, char buffer[], int flags,
int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags,
int width, int precision, int size);
int print_percent(va_list types, char buffer[], int flags,
int width, int precision, int size);
/* functions that print numbers */
int print_int(va_list types, char buffer[], int flags,
int width, int precision, int size);
int print_binary(va_list types, char buffer[], int flags,
int width, int precision, int size);
int print_unsigned(va_list types, char buffer[], int flags,
int width, int precision, int size);
int print_octal(va_list types, char buffer[], int flags,
int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[], int flags,
int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[], int flags,
int width, int precision, int size);
int print_hexa(va_list types, char map to[], char buffer[], int flags,
char flag_ch, int width, int precision, int size);
/* function that prints non-printable characters */
int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size);
/* function that prints memory address */
int print_pointer(va_list types, char buffer[], int flags,
int width, int precision, int size);
/* functions that handle other specifiers */
int get_flags(const char *format, int *j);
int get_width(const char *format, int *j, va_list list);
int get_precision(const char *format, int *j, va_list list);
int get_size(const char *format, int *j);
/* function that prints string in reverse */
int print_reverse(va_list types, char buffer[], int flags,
int width, int precision, int size);
/* functions for width handler */
int handle_write_char(char c, char buffer[],
int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width,
int precision, int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
int width, int flags, char padd, char extra_c, int padd_start);
int write_unsigned(int is_negative, int ind, char buffer[],
int flags, intwidth, int precision, int size);
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_size_number(long int num, int size);
long int convert_size_unsigned(unsigned long int num, int size);
#endif

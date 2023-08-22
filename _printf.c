#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/*
 * _printf - function
 * @format: the format
 * Return: printed characters
 */
int _printf(const char *format, ...)
{
int j, prints = 0, printed_chars = 0;
int flags, width, precision, size, buff_ind = 0;
va_list list;
char buffer[BUFF_SIZE];
if (format == NULL)
	return (-1);
va_start(list, format);
for (j =0; format && format[j] != '\0'; j++)
{
if (format[j] != '%')
{
buffer[buff_ind++] = format[j];
if (buff_ind == BUFF_SIZE)
	print_buffer(buffer, &buff_ind);
printed_chars++;
}
else
{
print_buffer(buffer, &buff_ind);
flags = get_flags(format, &j);
width = get_width(format, &j, list);
precision = get_precision(format, &j, list);
size = get_size(format, &j);
++j;
prints = handle_print(format, &j, list, buffer, flags, width, precision, size);
if (prints == -1)
	return (-1);
printed_chars += prints;
}
}
print_buffer(buffer, &buff_ind);
va_end(list);
return (printed_chars);
}
/**
 * print_buffer - prints buffers's contents
 * @buffer: array of characters
 * @buff_ind: indicates length
 */
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
	write(i, &buffer[0], *buff_ind);
*buff_ind = 0;
}

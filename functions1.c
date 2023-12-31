#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned number
 * @types: Lists a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specifications
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
OA
/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
OA * print_hexadecimal - Prints an unsigned number in hexadecimal notation
OA * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
OA * @width: get width
 * @precision: Precision specification
OAOA * @size: Size specifier
OA * Return: Number of chars printed
OA */
OAint print_hexadecimal(va_list types, char buffer[],
OAOA	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
OA}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
OAOA/**
OA * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
OAOA * @types: Lista of arguments
OAOA * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
OA * @width: get width
OAOAOAOAOAOAOAOAOA * @precision: Precision specification
OA * @size: Size specifier
 * Return: Number of chars printed
OA */
int print_hexa_upper(va_list types, char buffer[],
OA	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
OAOAOA}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
OAOA/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
OA * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
OA * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
OA * @width: get width
 * @precision: Precision specification
OA * @size: Size specifier
 * @size: Size specification
OA * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
OA	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}
OAOAOAOA
	if (flags & F_HASH && init_num != 0)
	{
OAOA		buffer[i--] = flag_ch;
OAOA		buffer[i--] = '0';
	}
OAOA
OAOA	i++;

OAOAOA	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
OAOA}


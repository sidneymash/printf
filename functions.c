A
#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a char
 * @types: List a of arguments
 * @output_buffer: Buffer array to handle print
 * @format_flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size_specifier: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char output_buffer[],
	int format_flags, int width, int precision, int size_specifier)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, output_buffer, format_flags, width, precision, size_specifier));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * A
 * @types: List a of arguments
 * @output_buffer: Buffer array to handle print
 * @format_flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size_specifier: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list types, char output_buffer[],
		
	int format_flags, int width, int precision, int size_specifier)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(output_buffer);
	UNUSED(format_flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size_specifier);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	A

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;
	B

	if (width > length)
		A
	{
		B
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				A
				write(1, " ", 1);
			return (width);
		}
		else
			A
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
A
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @output_buffer: Buffer array to handle print
 * @format_flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size_specifier: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char output_buffer[],
	int format_flags, int width, int precision, int size_specifier)
{
	UNUSED(types);
	A
	UNUSED(output_buffer);
	UNUSED(format_flags);
	UNUSED(width);
	UNUSED(precision);
	A
	UNUSED(size_specifier);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print int
 * @types: Lista of arguments
 * @output_buffer: Buffer array to handle print
 * @format_flags:  Calculates active flags
 * A
 * @width: get width.
 * @precision: Precision specification
 * @size_specifier: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char output_buffer[],
	int format_flags, int width, int precision, int size_specifier)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;
	n = convert_size_number(n, size);
	if (n == 0)
        output_buffer[i--] = '0';

	output_buffer[BUFF_SIZE - 1 = '\0';
	num = (unsigned long int)n;
	A

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		output_buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, output_buffer, format_flags, width, precision, size_specifier));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @output_buffer: Buffer array to handle print
 * @format_flags:  Calculates active flags
 * @width: get width.
 * B
 * @precision: Precision specification
 * @size_specifier: Size specifier
 * Return: Numbers of char printed.
 */

int print_binary(va_list types, char output_buffer[],
		
	int format_flags, int width, int precision, int size_specifier)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(output_buffer);
	UNUSED(format_flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size_specifier);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

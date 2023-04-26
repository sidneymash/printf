#include <stdio.h>
/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @format_index: List of arguments to be printed.
 *
 * Return: Precision.
 */

int get_size(const char *format, int *format_index)
{
	int curr_index = *format_index + 1;
	int size = 0;

	if (format[curr_index] == 'l')
		size = S_LONG;
	else if (format[curr_index] == 'h')
		size = S_SHORT;

	if (size == 0)
		*format_index = curr_index - 1;
	else
		*format_index = curr_index;

	return (size);
}

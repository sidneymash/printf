#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *format_index)
{
	int curr_index = *format_index + 1;
	int size_sps = 0;

	if (format[curr_index] == 'l')
		size_sps = S_LONG;
	else if (format[curr_index] == 'h')
		size_sps = S_SHORT;

	if (size_sps == 0)
		*format_index = curr_index - 1;
	else
		*format_index = curr_index;

	return (size_sps);
}

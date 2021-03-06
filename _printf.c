#include "holberton.h"

/**
 * _printf - Entry point
 * @format: string to print
 * Return: count.
 */

int _printf(const char *format, ...)
{
	int count = -1;
	data_t type[] = {
		{"c", print_char}, {"s", print_char_2}, {"d", print_int},
		{"i", print_int}, {"b", print_to_binar}, {"%", print_percent},
		{"u", print_uns}, {"o", print_octal}, {"x", print_hexa_low},
		{"X", print_hexa_upper}, {"S", print_str_non_print},
		{"r", print_str_rev}, {"R", print_rot13}, {NULL, NULL},
	};
	va_list list;

	if (format)
	{
		va_start(list, format);
		count = functions(format, type, list);
		va_end(list);
	}
	return (count);
}

/**
 * functions - Entry point
 * @format: string to print
 * @type: data type.
 * @list: arguments.
 * Return: count
 */

int functions(const char *format, data_t type[], va_list list)
{
	int i, indx_type, iter = 0, count = 0;

	while (format[iter])
	{
		if (format[iter] != '%')
		{
			_putchar(format[iter]);
			count++;
		}
		if (format[iter] == '%')
		{
			if (format[iter + 1] == '\0')
				return (-1);
			iter++;
			for (i = 0, indx_type = 0; type[indx_type].type != NULL ; i++, indx_type++)
			{
				if (*type[indx_type].type == format[iter])
				{
					count += type[indx_type].func(list);
					break;
				}
			}
			if (type[indx_type].type == NULL && format[iter] != ' ')
			{
				if (format[iter] != '\0')
				{
					_putchar(format[iter - 1]);
					_putchar(format[iter]);
					count += 2;
				}
				else
					return (-1);
			}
		}
		iter = iter + 1;
	}
	return (count);
}

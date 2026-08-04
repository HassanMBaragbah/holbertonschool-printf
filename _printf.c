#include "main.h"

/**
 * _printf - Formatted output conversion and print
 * @format: Input string format
 *
 * Return: Total characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	int (*func)(va_list);

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}

			func = get_spec_func(format[i]);
			if (func != NULL)
			{
				count += func(args);
			}
			else
			{
				count += write(1, "%", 1);
				count += write(1, &format[i], 1);
			}
		}
		else
		{
			count += write(1, &format[i], 1);
		}
		i++;
	}

	va_end(args);
	return (count);
}

#include "main.h"

/**
 * print_char - Prints a character
 * @args: List of arguments
 * Return: Number of characters printed (1)
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_string - Prints a string
 * @args: List of arguments
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int i = 0;

	if (str == NULL)
		str = "(null)";

	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

/**
 * print_percent - Prints a percent sign
 * @args: List of arguments (unused)
 * Return: Number of characters printed (1)
 */
int print_percent(va_list args)
{
	(void)args;
	return (write(1, "%", 1));
}

/**
 * print_int - Prints an integer (%d and %i)
 * @args: List of arguments
 * Return: Number of characters printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	unsigned int num;
	int div = 1;
	char c;

	if (n < 0)
	{
		count += write(1, "-", 1);
		num = -n;
	}
	else
	{
		num = n;
	}

	while (num / div > 9)
		div *= 10;

	while (div != 0)
	{
		c = (num / div) + '0';
		count += write(1, &c, 1);
		num %= div;
		div /= 10;
	}

	return (count);
}

/**
 * print_binary - Converts and prints an unsigned int in binary (%b)
 * @args: List of arguments
 * Return: Number of characters printed
 */
int print_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int binary[32];
	int i = 0, count = 0;
	char c;

	if (n == 0)
		return (write(1, "0", 1));

	while (n > 0)
	{
		binary[i] = n % 2;
		n /= 2;
		i++;
	}

	for (i = i - 1; i >= 0; i--)
	{
		c = binary[i] + '0';
		count += write(1, &c, 1);
	}

	return (count);
}

#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer (%u)
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int print_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int num = n;
	unsigned int div = 1;
	int count = 0;
	char c;

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
 * print_octal - Prints an unsigned integer in octal (%o)
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int print_octal(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int octal[11];
	int i = 0, count = 0;
	char c;

	if (n == 0)
		return (write(1, "0", 1));

	while (n > 0)
	{
		octal[i] = n % 8;
		n /= 8;
		i++;
	}

	for (i = i - 1; i >= 0; i--)
	{
		c = octal[i] + '0';
		count += write(1, &c, 1);
	}

	return (count);
}

/**
 * print_hex_low - Prints an unsigned int in lowercase hex (%x)
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int print_hex_low(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int hex[8];
	int i = 0, count = 0;
	char c;

	if (n == 0)
		return (write(1, "0", 1));

	while (n > 0)
	{
		hex[i] = n % 16;
		n /= 16;
		i++;
	}

	for (i = i - 1; i >= 0; i--)
	{
		if (hex[i] < 10)
			c = hex[i] + '0';
		else
			c = (hex[i] - 10) + 'a';
		count += write(1, &c, 1);
	}

	return (count);
}

/**
 * print_hex_up - Prints an unsigned int in uppercase hex (%X)
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int print_hex_up(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int hex[8];
	int i = 0, count = 0;
	char c;

	if (n == 0)
		return (write(1, "0", 1));

	while (n > 0)
	{
		hex[i] = n % 16;
		n /= 16;
		i++;
	}

	for (i = i - 1; i >= 0; i--)
	{
		if (hex[i] < 10)
			c = hex[i] + '0';
		else
			c = (hex[i] - 10) + 'A';
		count += write(1, &c, 1);
	}

	return (count);
}

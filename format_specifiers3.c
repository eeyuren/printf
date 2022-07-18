#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_u - Prints Unsigned integers
 * @args: List of all of the argumets
 * Return: a count of the numbers
 */
int print_u(va_list args)
{
	unsigned int num;

	num = va_arg(args, unsigned int);

	if (num == 0)
		return (print_unsigned_number(num));

	if (num < 1)
		return (-1);
	return (print_unsigned_number(num));
}

/**
 * _pow - calculates an exponent
 * @base: base of exponent
 * @exponent: exponent of number
 *
 * Return: base ^ exponent
 */
static unsigned long _pow(unsigned int base, unsigned int exponent)
{
	unsigned int i;
	unsigned long ans = base;

	for (i = 1; i < exponent; i++)
	{
		ans *= base;
	}
	return (ans);
}

/**
 * print_p - prints an address
 * @p: address to print
 *
 * Return: number of characters to print
 */
int print_p(va_list p)
{
	int count = 0;
	unsigned int a[16];
	unsigned int i, sum;
	unsigned long n, m;
	char *str = "(nil)";

	n = va_arg(p, unsigned long);
	if (n == 0)
	{
		for (i = 0; str[i]; i++)
		{
			_putchar(str[i]);
			count++;
		}
		return (count);
	}
	_putchar('0');
	_putchar('x');
	count = 2;
	m = _pow(16, 15); /* 16 ^ 15 */
	a[0] = n / m;
	for (i = 1; i < 16; i++)
	{
		m /= 16;
		a[i] = (n / m) % 16;
	}
	for (i = 0, sum = 0; i < 16; i++)
	{
		sum += a[i];
		if (sum || i == 15)
		{
			if (a[i] < 10)
				_putchar('0' + a[i]);
			else
				_putchar('0' + ('a' - ':') + a[i]);
			count++;
		}
	}
	return (count);
}
/**
 * print_reversed - Calls a function to reverse and print a string
 * @arg: Argument passed to the function
 * Return: The amount of characters printed
 */
int print_reversed(va_list arg)
{
	int len;
	char *str;
	char *ptr;

	str = va_arg(arg, char *);
	if (str == NULL)
		return (-1);
	ptr = rev_string(str);
	if (ptr == NULL)
		return (-1);
	for (len = 0; ptr[len] != '\0'; len++)
		_putchar(ptr[len]);
	free(ptr);
	return (len);
}
/**
 * rot13 - Converts string to rot13
 * @args: string to convert
 * Return: converted string
 */
int rot13(va_list args)
{
	int i;
	int x;
	char *str;
	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char u[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);
	if (str == NULL)
		return (-1);
	for (i = 0; str[i] != '\0'; i++)
	{
		for (x = 0; x <= 52; x++)
		{
			if (str[i] == s[x])
			{
				_putchar(u[x]);
				break;
			}
		}
		if (x == 53)
			_putchar(str[i]);
	}
	return (i);
}

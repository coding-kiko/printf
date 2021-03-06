#include "holberton.h"

/**
 * print_uns - print unsigned integer
 * @list: string to print.
 *
 * Return: Calls function that prints any unsigned number.
 */

int print_uns(va_list list)
{
	return (print_number_uns(va_arg(list, int)));
}

/**
 * print_octal - Entry point
 * @list: string to print
 * Return: Always 0 (Success)
 */
int print_octal(va_list list)
{
	int i = 0, count = 0;
	int hexnum[100];
	unsigned int n = va_arg(list, unsigned int);
	unsigned int m = 1, aux, num = 0;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
	while (n > 0)
	{
		aux = n % 8;
		hexnum[i] = aux;
		i++;
		num = (aux * m) + num;
		n = n / 8;
		m = m * 10;
	}
	for (i = i - 1; i >= 0; i--)
	{
		_putchar(hexnum[i] + '0');
		count++;
	}
	return (count);
}

/**
 * print_hexa_low - Entry point
 * @list: string to print
 * Return: Always 0 (Success)
 */
int print_hexa_low(va_list list)
{
	int rem, i = 0, count = 0;
	char hexnum[100];
	unsigned int decnum = va_arg(list, unsigned int);

	if (decnum == 0)
	{
		_putchar('0');
		return (1);
	}
	while (decnum != 0)
	{
		rem = decnum % 16;
		if (rem < 10)
			rem = rem + 48;
		else
			rem = rem + 87;
		hexnum[i] = rem;
		i++;
		decnum = decnum / 16;
	}
	for (i = i - 1; i >= 0; i--)
	{
		_putchar(hexnum[i]);
		count++;
	}
	return (count);
}

/**
 * print_hexa_upper - Entry point
 * @list: string to print
 * Return: Always 0 (Success)
 */
int print_hexa_upper(va_list list)
{
	int rem, i = 0, count = 0;
	char hexnum[100];
	unsigned int decnum = va_arg(list, unsigned int);

	if (decnum == 0)
	{
		_putchar('0');
		return (1);
	}
		while (decnum != 0)
	{
		rem = decnum % 16;
		if (rem < 10)
			rem = rem + 48;
		else
			rem = rem + 55;
		hexnum[i] = rem;
		i++;
		decnum = decnum / 16;
	}
	for (i = i - 1; i >= 0; i--)
	{
		_putchar(hexnum[i]);
		count++;
	}
	return (count);
}

/**
 * print_str_non_print - Entry point
 * @list: string to print
 * Return: Always 0 (Success)
 */

int print_str_non_print(va_list list)
{
	char *s_aux;
	int rem, decnum, i = 0, cont = 0, count = 0;
	int hexnum[100];

	s_aux = va_arg(list, char*);
	if (!s_aux)
		s_aux = "(null)";
	while (s_aux[cont])
	{
		if ((s_aux[cont] > 0 && s_aux[cont] < 32) || (s_aux[cont] >= 127))
		{
			decnum = (int)s_aux[cont];
			while (decnum != 0)
			{
				rem = decnum % 16;
				if (rem < 10)
					rem = rem + 48;
				else
					rem = rem + 55;
				hexnum[i] = rem;
				i++;
				decnum = decnum / 16;
			}
			_putchar(92);
			_putchar('x');
			i = i - 1;
			if (i < 1)
				_putchar('0');
			for (; i >= 0; i--)
			{
				_putchar(hexnum[i]);
			}
			i = 0;
			count += 3;
		}
		else
			_putchar(s_aux[cont]);
		cont++;
	}
	return (cont + count);
}

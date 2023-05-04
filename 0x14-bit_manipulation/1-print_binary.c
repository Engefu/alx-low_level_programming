#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: unsigned long int number to print in binary
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	/* Find the most significant bit */
	unsigned long int mask = 1UL << ((sizeof(unsigned long int) * 8) - 1);

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	/* Print the binary representation */
	while (mask > 0)
	{
		if (n & mask)
			_putchar('1');
		else
			_putchar('0');
		mask >>= 1;
	}
}

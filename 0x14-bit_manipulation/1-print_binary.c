#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to print.
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int bit;

	/* Shift mask to leftmost bit */
	mask <<= (sizeof(unsigned long int) * 8) - 1;

	for (bit = 0; bit < (int)(sizeof(unsigned long int) * 8); bit++)
	{
		if ((n & mask) == 0)
			_putchar('0');
		else
			_putchar('1');

		/* Shift mask one bit to the right */
		mask >>= 1;
	}
}

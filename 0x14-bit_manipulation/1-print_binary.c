#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: the number to convert to binary and print
 */
void print_binary(unsigned long int n)
{
	/* Find the most significant bit position */
	unsigned long int mask = 1;
	int msb_pos = 0;

	while ((n >> msb_pos) > 0)
		msb_pos++;

	msb_pos--;

	/* Print binary representation */
	while (msb_pos >= 0)
	{
		if ((n >> msb_pos) & mask)
			_putchar('1');
	else
		_putchar('0');
	msb_pos--;
	}
}

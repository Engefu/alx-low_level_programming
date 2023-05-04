#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 *
 * @n: The number to be printed in binary.
 */
void print_binary(unsigned long int n)
{
	int flag = 0;

	if (n == 0)
		_putchar('0');

	for (unsigned long int mask = 1UL << ((sizeof(unsigned long int) * 8) - 1); mask != 0; mask >>= 1)
	{
		if (n & mask)
		{
			_putchar('1');
			flag = 1;
		}
		else if (flag == 1)
			_putchar('0');
	}
}

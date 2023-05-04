#include "main.h"

/**
 * flip_bits - Returns the number of bits you would need to flip to get from
 *             one number to another.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits needed to flip to get from one number to another.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int bits = 0;
	unsigned long int flip = n ^ m;

	while (flip > 0)
	{
		if ((flip & 1) == 1)
			bits++;

		flip >>= 1;
	}

	return (bits);
}

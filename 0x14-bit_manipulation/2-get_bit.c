#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index
 * @n: Number to search bit in
 * @index: Index starting from 0 of the bit to get
 * Return: Value of the bit at index or -1 if error occurs
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int num_bits;

	/* Find number of bits in the number */
	num_bits = sizeof(unsigned long int) * 8;

	/* Check if index is within bounds */
	if (index >= num_bits)
		return (-1);

	/* Right shift number to get bit at given index in rightmost position */
	n >>= index;

	/* Mask bit to get its value */
	return (n & 1);
}

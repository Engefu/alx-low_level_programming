#include <stdio.h>
#include "lists.h"  // include the header file

/**
 * print_list - prints all the elements of a linked list
 * @h: head of the linked list
 *
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
    size_t count = 0; // initialize count variable to zero

    while (h)
 	{
 	if (!h->str)
 	printf("[0] (nil)\n");
 	else
 	printf("[%u] %s\n", h->len, h->str);
	h = h->next;
 	count++;
 	}	
}

    return (count); // return the number of nodes
}

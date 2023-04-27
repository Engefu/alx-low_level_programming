#include "lists.h"  // include the header file
#include <stdio.h>

/**
 * print_list - prints all the elements of a linked list
 * @h: head of the linked list
 *
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
    size_t count = 0; // initialize count variable to zero

    while (h != NULL) // traverse the linked list
    {
        if (h->str == NULL) // check if string is null
            printf("[%d] (nil)\n", h->len);
        else
            printf("[%d] %s\n", h->len, h->str);

        count++; // increment the count variable
        h = h->next; // move to the next node
    }

    return (count); // return the number of nodes
}

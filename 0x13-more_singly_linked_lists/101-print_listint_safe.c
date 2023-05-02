#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_listint_safe - Prints a listint_t linked list, safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current = head, *temp;
	size_t count = 0;
	const listint_t *tmp;

	if (head == NULL)
		exit(98);

	while (tmp)
	{
		printf("[%p] %d\n", (void *)tmp, tmp->n);
		count++;

		if (tmp >= tmp->next)
		{
			printf("-> [%p] %d\n", (void *)tmp->next, tmp->next->n);
			break;
		}

		tmp = tmp->next;
	}

	return (count);
}

#include "lists.h"
#include <stdlib.h>

/**
 * free_listint - Frees a listint_t list.
 * @head: Pointer to the head of the list.
 */
void free_listint(listint_t *head)
{
	listint_t *current = head;
	listint_t *temp;

	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}

	head = NULL;
}

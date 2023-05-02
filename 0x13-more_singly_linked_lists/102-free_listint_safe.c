#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list.
 *
 * @h: A pointer to the address of the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current, *temp;
	size_t count = 0;

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;
	while (current != NULL)
	{
		count++;
		if (current <= current->next)
		{
			printf("Freeing node with unique address: %p\n", (void *)current);
			temp = current;
			current = current->next;
			free(temp);
		}
		else
		{
			printf("Loop detected, exiting...\n");
			*h = NULL;
			exit(98);
		}
	}
	*h = NULL;
	return (count);
}

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
	size_t size = 0;
	listint_t *current, *next;

	if (h == NULL)
		return (size);

	current = *h;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		size++;
		if ((void *)current <= (void *)next)
			break;
		current = next;
	}

	*h = NULL;
	return (size);
}

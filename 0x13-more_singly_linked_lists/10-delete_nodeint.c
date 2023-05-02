#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at index index of a listint_t
 * linked list.
 * @head: A pointer to the head of the listint_t list.
 * @index: The index of the node to delete.
 *
 * Return: If the function succeeds - 1.
 *         If it fails - -1.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *tmp, *prev;

	if (*head == NULL)
		return (-1);

	tmp = *head;

	if (index == 0)
	{
		*head = (*head)->next;
		free(tmp);
		return (1);
	}

	for (i = 0; i < index; i++)
	{
	if (tmp->next == NULL)
		return (-1);

	prev = tmp;
	tmp = tmp->next;
	}

	prev->next = tmp->next;
	free(tmp);

	return (1);
}

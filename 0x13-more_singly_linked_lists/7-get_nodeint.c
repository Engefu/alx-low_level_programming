#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @head: A pointer to the head node of the listint_t list.
 * @index: The index of the node, starting at 0.
 *
 * Return: If the node does not exist, return NULL.
 *         Otherwise, return a pointer to the nth node.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0; /* Index of node */
	listint_t *current = head; /* Current node */

	while (current != NULL)
	{
		if (i == index)
			return (current); /* Node found at index */

	i++;
	current = current->next; /* Move to next node */
	}

	/* Node not found at index */
	return (NULL);
}

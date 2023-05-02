#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to pointer of the first node of a listint_t list
 * @idx: index of the list where the new node should be added
 * @n: integer to be included in the new node
 *
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *temp = *head;
	unsigned int i = 0;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	while (temp && i < idx - 1)
	{
		temp = temp->next;
		i++;
	}
	if (!temp)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = temp->next;
	temp->next = new_node;

	return (new_node);
}

#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list,
 * and returns the head node's data (n).
 * @head: pointer to the head of the list
 *
 * Return: the data value of the deleted head node, or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
	int data;
	listint_t *temp;

	if (*head == NULL) /* check if the list is empty */
		return (0);

	data = (*head)->n; /* get the data of the head node */

	temp = *head; /* use a temporary pointer to free the head node */
	*head = (*head)->next; /* move the head to the next node */

	free(temp); /* free the old head node */

	return (data); /* return the data of the deleted node */
}

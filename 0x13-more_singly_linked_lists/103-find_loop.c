#include "lists.h"

/**
 * find_listint_loop - finds the node where a linked list loops
 * @head: pointer to first node of linked list
 *
 * Return: pointer to node where loop starts or NULL if no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	slow = head;
	fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			slow = head;
			while (slow && fast)
			{
				if (slow == fast)
					return (slow);
				slow = slow->next;
				fast = fast->next;
			}
			return (NULL);
		}
	}
	return (NULL);
}


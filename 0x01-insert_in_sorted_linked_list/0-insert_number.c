#include "lists.h"
#include <stdlib.h>

/**
 * insert_node -  inserts a number into a sorted singly linked list
 * @head: pointer to a pointer to the head of a list
 * @number: const integer to be added to the listint_t list
 *
 * Return: The address of the new node.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node = NULL, *tmp = NULL;

	/* create new node in memory */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = number, new_node->next = NULL;
	/* new node as head */
	if (*head == NULL)
	{
		new_node->n = number;
		*head = new_node;
		return (new_node);
	}
	/* insert as first node */
	tmp = *head;
	if (number <= tmp->n)
	{
		new_node->n = number;
		new_node->next = tmp;
		*head = new_node;
		return (new_node);
	}
	/* traverse list: move the tmp to the next one if it's not equal to null */
	/* insert node in the middle and the finish of the list */
	while (tmp->next != NULL)
	{
		if (tmp->next->n >= number)
			break;
		tmp = tmp->next;
	}
	new_node->n = number, new_node->next = tmp->next, tmp->next = new_node;
	return (new_node);
	if (tmp->next == NULL)
	{
		new_node->n = number;
		tmp->next = new_node;
		return (new_node);
	}
}

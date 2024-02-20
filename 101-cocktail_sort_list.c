#include "sort.h"
#include <stdio.h>

/**
 * swap - swaps a node with its previous node
 * @node: node to swap
 * @list: pointer to the head of the list
 * Return: pointer to the swapped node
 */
listint_t *swap(listint_t *node, listint_t **list)
{
	listint_t *b = node->prev, *c = node;

	b->next = c->next;
	if (c->next)
		c->next->prev = b;
	c->next = b;
	c->prev = b->prev;
	b->prev = c;
	if (c->prev)
		c->prev->next = c;
	else
		*list = c;
	return (c);
}

/**
 * cocktail_sort_list - performs a cocktail shaker sort on a linked list
 * @list: pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *n;
	int s = 1;

	if (!list || !(*list) || !(*list)->next)
		return;
	n = *list;
	while (s == 1)
	{
		s = 0;
		while (n->next)
		{
			if (n->n > n->next->n)
			{
				n = swap(n->next, list);
				s = 1;
				print_list(*list);
			}
			n = n->next;
		}
		if (s == 0)
			break;
		s = 0;
		while (n->prev)
		{
			if (n->n < n->prev->n)
			{
				n = swap(n, list);
				s = 1;
				print_list(*list);
			}
			else
				n = n->prev;
		}
	}
}


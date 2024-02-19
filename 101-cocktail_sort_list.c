#include "sort.h"
/**
 * _swap - Swaps two nodes of doubly linked list
 * @node: node base to change
 * @list: double link list head
 * Return: No Return
 */
void _swap(listint_t **node, listint_t **list)
{
	listint_t *tmp = *node, *tmp2;

	if (!tmp || !tmp->next)
		return;

	tmp2 = tmp->next;

	tmp->next = tmp2->next;
	if (tmp->next)
		tmp->next->prev = tmp;

	tmp2->prev = tmp->prev;
	if (tmp2->prev)
		tmp2->prev->next = tmp2;

	tmp->prev = tmp2;
	tmp2->next = tmp;

	if (!tmp2->prev)
		*list = tmp2;

	*node = tmp2;
}

/**
 * cocktail_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Cocktail shaker sort algorithm
 * @list: head of list to be sortered (Double Linked List)
 * Return: No Return
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *aux;
	int a, b, c;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;
	while (1)
	{
		a = 0;
		b = -1;
		c = -1;
		head = *list;
		while (c >= b)
		{
			b++;
			while (head->next && a != c)
			{
				if (head->n > head->next->n)
				{
					aux = head;
					_swap(&aux, list);
					print_list(*list);
					head = aux;
				}
				a++;
				head = head->next;
			}
			if (b == 0)
				c = a;
			c--;
			while (head->prev && a >= b)
			{
				if (head->n < head->prev->n)
				{
					aux = head->prev;
					_swap(&aux, list);
					print_list(*list);
					head = aux->next;
				}
				a--;
				head = head->prev;
			}
		}
		if (a <= 1)
			break;
	}
}


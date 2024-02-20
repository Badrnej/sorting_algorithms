#include "deck.h"
#include <stdio.h>
/**
 *_strcmp - compare two strings
 *@s1: string
 *@s2: string
 *Return: 1 if s1 and s2 are equal, 0 otherwise
 */
int _strcmp(const char *s1, const char *s2)
{
	size_t i = 0;

	if (*s1 == '\0')
		return (0);
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] == '\0' && s2[i])
		return (0);
	return (1);
}
/**
 * get_pos - return the position based on the card value
 * @node: the card node
 * Return: the card position
 */
int get_pos(deck_node_t *node)
{
	int value;

	value = (*node).card->value[0] - '0';
	if (value < 50 || value > 57)
	{
		if (_strcmp((*node).card->value, "Ace") == 1)
			value = 1;
		else if (_strcmp((*node).card->value, "10") == 1)
			value = 10;
		else if (_strcmp((*node).card->value, "Jack") == 1)
			value = 11;
		else if (_strcmp((*node).card->value, "Queen") == 1)
			value = 12;
		else if (_strcmp((*node).card->value, "King") == 1)
			value = 13;
	}
	value += (*node).card->kind * 13;
	return (value);
}
/**
 *swap - swap a card with its previous one
 *@card: the card to swap
 *@deck: the deck
 *Return: a pointer to the entered card
 */
deck_node_t *swap(deck_node_t *card, deck_node_t **deck)
{
	deck_node_t *back = card->prev, *current = card;
	/*NULL, 19, 48, 9, 71, 13, NULL*/

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*deck = current;
	return (current);
}

/**
 * insertion_sort - sorts a doubly linked deck
 *			in ascending order using Insertion sort
 * @deck: the deck to sort
 */
void insertion_sort(deck_node_t **deck)
{
	int value_prev, value_current;
	deck_node_t *node;

	if (deck == NULL || (*deck)->next == NULL)
		return;
	node = (*deck)->next;
	while (node)
	{
		if (node->prev)
		{
			value_prev = get_pos((node->prev));
			value_current = get_pos(node);
		}
		while ((node->prev) && (value_prev > value_current))
		{
			value_prev = get_pos((node->prev));
			value_current = get_pos(node);
			node = swap(node, deck);

		}
		node = node->next;
	}
}
/**
 * sort - sorts a deck using insertion sort algorithm
 * @deck: the deck to sort
 */
void sort(deck_node_t **deck)
{
	insertion_sort(deck);
}


#include "deck.h"
#include <stdio.h>

/**
 * cmp_str - compare two strings
 * @str1: string
 * @str2: string
 * Return: 1 if str1 and str2 are equal, 0 otherwise
 */
int cmp_str(const char *str1, char *str2)
{
	size_t i = 0;

	if (str1 == '\0')
		return (0);
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	if (str1[i] == '\0' && str2[i])
		return (0);
	return (1);
}

/**
 * get_position - return the position based on the card you put in
 * @node: represent the card
 * Return: return the card position
 */
int get_position(deck_node_t *node)
{
	int val;

	val = (*node).card->value[0] - '0';
	if (val < 50 || val > 57)
	{
		if (cmp_str((*node).card->value, "Ace") == 1)
			val = 1;
		else if (cmp_str((*node).card->value, "10") == 1)
			val = 10;
		else if (cmp_str((*node).card->value, "Jack") == 1)
			val = 11;
		else if (cmp_str((*node).card->value, "Queen") == 1)
			val = 12;
		else if (cmp_str((*node).card->value, "King") == 1)
			val = 13;
	}
	val += (*node).card->kind * 13;
	return (val);
}

/**
 * swap - swap a card for its previous one
 * @card: card
 * @deck: card deck
 * Return: return a pointer to a card which was entered
 */
deck_node_t *swap(deck_node_t *card, deck_node_t **deck)
{
	deck_node_t *back = card->prev, *current = card;

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
 * insertion_sort - function that sorts a doubly linked deck
 * of integers in ascending order using the Insertion sort algorithm
 * @deck: Doubly linked deck to sort
 */
void insertion_sort(deck_node_t **deck)
{
	int val_prev, val_current;
	deck_node_t *node;

	if (deck == NULL || (*deck)->next == NULL)
		return;
	node = (*deck)->next;
	while (node)
	{
		if (node->prev)
		{
			val_prev = get_position((node->prev));
			val_current = get_position(node);
		}
		while ((node->prev) && (val_prev > val_current))
		{
			val_prev = get_position((node->prev));
			val_current = get_position(node);
			node = swap(node, deck);
		}
		node = node->next;
	}
}

/**
 * sort - sort a deck you put in using
 * insertion sort algorithm
 * @deck: deck
 */
void sort(deck_node_t **deck)
{
	insertion_sort(deck);
}


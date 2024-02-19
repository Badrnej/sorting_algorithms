#include "deck.h"

int _strcmp(char *s1, const char *s2)
{
	while (*s1 != '\0')
	{
		if (*s2 == '\0')
			return (*s1);
		if (*s2 > *s1)
			return (*s1 - *s2);
		if (*s1 > *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s2 != '\0')
		return (*s2);
	return (0);
}

void _swap(deck_node_t **node, deck_node_t **deck)
{
	deck_node_t *tmp = *node, *tmp2, *tmp3;

	if (!(*node)->prev)
		*deck = (*node)->next;

	tmp = tmp3 = *node;
	tmp2 = tmp->next;

	tmp->next = tmp2->next;
	tmp3 = tmp->prev;
	tmp->prev = tmp2;
	tmp2->next = tmp;
	tmp2->prev = tmp3;

	if (tmp2->prev)
		tmp2->prev->next = tmp2;

	if (tmp->next)
		tmp->next->prev = tmp;

	*node = tmp2;
}

int CardValue(deck_node_t *cardNode)
{
	char *cardnum[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10",
			     "Jack", "Queen", "King"};
	int value, i;
	const char *cnum;

	cnum = cardNode->card->value;
	for (i = 0; i < 13;  i++)
		if (!_strcmp(cardnum[i], cnum))
		{
			i++;
			break;
		}

	value = i + (cardNode->card->kind) * 13;

	return (value);
}

void sort_deck(deck_node_t **deck)
{
	deck_node_t *h, *t, *a;

	if (!deck || !(*deck) || (!((*deck)->prev) && !((*deck)->next)))
		return;

	h = *deck;
	while (h && h->next)
	{
		if (CardValue(h) > CardValue(h->next))
		{
			a = h;

			_swap(&a, deck);
			h = a;
			t = a;

			while (t && t->prev)
			{
				if (CardValue(t) < CardValue(t->prev))
				{
					a = t->prev;

					_swap(&(a), deck);

					t = a->next;
				}

				t = t->prev;
			}
		}
		h = h->next;
	}
}


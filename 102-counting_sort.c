#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @arr: An array of integers.
 * @size: The size of the array.
 * Return: The maximum integer in the array.
 */
int get_max(int *arr, int size)
{
	int m, i;

	for (m = arr[0], i = 1; i < size; i++)
	{
		if (arr[i] > m)
			m = arr[i];
	}

	return (m);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @arr: An array of integers.
 * @size: The size of the array.
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *arr, size_t size)
{
	int *c, *s, m, i;

	if (arr == NULL || size < 2)
		return;

	s = malloc(sizeof(int) * size);
	if (s == NULL)
		return;
	m = get_max(arr, size);
	c = malloc(sizeof(int) * (m + 1));
	if (c == NULL)
	{
		free(s);
		return;
	}

	for (i = 0; i < (m + 1); i++)
		c[i] = 0;
	for (i = 0; i < (int)size; i++)
		c[arr[i]] += 1;
	for (i = 0; i < (m + 1); i++)
		c[i] += c[i - 1];
	print_array(c, m + 1);

	for (i = 0; i < (int)size; i++)
	{
		s[c[arr[i]] - 1] = arr[i];
		c[arr[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		arr[i] = s[i];

	free(s);
	free(c);
}


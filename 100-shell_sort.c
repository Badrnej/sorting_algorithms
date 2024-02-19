#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @arr: An array of integers.
 * @len: The size of the array.
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *arr, size_t len)
{
	size_t gap, i, j;

	if (arr == NULL || len < 2)
		return;

	for (gap = 1; gap < (len / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < len; i++)
		{
			j = i;
			while (j >= gap && arr[j - gap] > arr[j])
			{
				swap_ints(arr + j, arr + (j - gap));
				j -= gap;
			}
		}
		print_array(arr, len);
	}
}

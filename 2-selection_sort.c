#include "sort.h"

/**
 * swap_ints - Swap two integers in an array
 * @x: The first integer to swap
 * @y: The second integer to swap
 */
void swap_ints(int *x, int *y)
{
	int swp;

	swp = *x;
	*x = *y;
	*y = swp;
}

/**
 * selection_sort - Sorts array of integers in ascending
 *		order using selection sort.
 * @array: An array of integers
 * @size: The size of the array
 *
 * Description: Prints the array after each swap
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t a, b;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		min = array + a;
		for (b = a + 1; b < size; b++)
			min = (array[b] < *min) ? (array + b) : min;

		if ((array + a) != min)
		{
			swap_ints(array + a, min);
			print_array(array, size);
		}
	}
}

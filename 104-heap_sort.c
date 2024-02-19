#include "sort.h"

/**
 * _swap - Swap 2 values in an array.
 * @arr: The array to swap values in.
 * @i: First index
 * @j: Second index
 * @r_size: Constant size for print
 * Return: Nothing
 */
void _swap(int *arr, int i, int j, const int r_size)
{
	int tmp;
	(void)r_size;

	if (i != j)
	{
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
		print_array(arr, (size_t)r_size);
	}
}

/**
 * _largest - Find the largest number between the layers
 * @arr: The array to sort
 * @size: The size of the array
 * @i: The largest index
 * @r_size: The size for print in swap
 * Return: Nothing
 */
void _largest(int *arr, size_t size, int i, const int r_size)
{
	int largest = i;
	int left = (2 * i) + 1;
	int right = (2 * i) + 2;

	if (left < (int)size && arr[left] > arr[largest])
		largest = left;

	if (right < (int)size && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{
		_swap(arr, i, largest, r_size);
		_largest(arr, size, largest, r_size);
	}
}

/**
 * heap_sort - Call _largest while layers exist
 * @arr: The array to sort
 * @size: Size of the array
 * Return: Nothing
 */
void heap_sort(int *arr, size_t size)
{
	const int r_size = (const int)size;
	int i;

	if (size < 2 || !arr)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		_largest(arr, size, i, r_size);

	for (i = size - 1; i >= 0; i--)
	{
		_swap(arr, 0, i, r_size);
		_largest(arr, i, 0, r_size);
	}
}

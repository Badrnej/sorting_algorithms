#include "sort.h"

void bitonic_caller(int *arr, int start, int s_size, int dir, int f_size);
void bitonic_merger(int *arr, int start, int s_size, int dir, int f_size);

/**
 * swap - Swap two elements in an array.
 * @a: int
 * @b: int
 * Return: Always 0
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * print_arr - Customized print_array function.
 * @arr: The array to be printed
 * @start: Starting index
 * @end: Ending index
 * Return: Always 0
 */
void print_arr(const int *arr, size_t start, size_t end)
{
	size_t i;

	i = start;
	while (arr && i <= end)
	{
		if (i > start)
			printf(", ");
		printf("%d", arr[i]);
		++i;
	}
	printf("\n");
}

/**
 * bitonic_sort - Sort an array using bitonic sort.
 * @arr: The array to be sorted
 * @size: The size of the array
 * Return: Always 0
 */
void bitonic_sort(int *arr, size_t size)
{
	int dir = 1;

	if (size < 2 || !arr)
		return;

	bitonic_caller(arr, 0, size, dir, size);
}

/**
 * bitonic_caller - Recursive bitonic function.
 * @arr: The array to be sorted
 * @start: Starting index
 * @s_size: Sub-array size
 * @dir: Direction of sorting
 * @f_size: Full array size
 * Return: Always 0
 */
void bitonic_caller(int *arr, int start, int s_size, int dir, int f_size)
{
	if (s_size > 1)
	{
		int s = s_size / 2;

		printf("Merging [%d/%d] ", s_size, f_size);
		printf(dir == 1 ? "(UP):\n" : "(DOWN):\n");
		print_arr(arr, start, start + s_size - 1);

		bitonic_caller(arr, start, s, 1, f_size);
		bitonic_caller(arr, start + s, s, -1, f_size);

		bitonic_merger(arr, start, s_size, dir, f_size);

		printf("Result [%d/%d] ", s_size, f_size);
		printf(dir == 1 ? "(UP):\n" : "(DOWN):\n");
		print_arr(arr, start, start + s_size - 1);
	}
}

/**
 * bitonic_merger - Merge the bitonic subarrays.
 * @arr: The array to be sorted
 * @start: Starting index
 * @s_size: Sub-array size
 * @dir: Direction of sorting
 * @f_size: Full array size
 * Return: Always 0
 */
void bitonic_merger(int *arr, int start, int s_size, int dir, int f_size)
{
	if (s_size > 1)
	{
		int s = s_size / 2;
		int i = start;

		while (i < s + start)
		{
			if (dir == 1)
			{
				if (arr[i] > arr[i + s])
					swap(&arr[i], &arr[i + s]);
			}
			else
			{
				if (arr[i] < arr[i + s])
					swap(&arr[i], &arr[i + s]);
			}
			i++;
		}

		bitonic_merger(arr, start, s, dir, f_size);
		bitonic_merger(arr, start + s, s, dir, f_size);
	}
}


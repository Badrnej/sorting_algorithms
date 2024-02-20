#include "sort.h"

void caller_bitonic(int *array, int start, int s_size, int dir, int f_size);
void merger_bitonic(int *array, int start, int s_size, int dir, int f_size);


/**
 * swap- swap two elements in array
 * @low: int
 * @high: int
 * Return: always 0
 */


void swap(int *low, int *high)
{
	int temp;

	temp = *low;
	*low = *high;
	*high = temp;
}


/**
 * print_array2 - Customized print_array
 * @array: The array to be printed
 * @start: starting index
 * @end: ending index
 * Return: always 0
 */
void print_array2(const int *array, size_t start, size_t end)
{
	size_t i;

	i = start;
	while (array && i <= end)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}

/**
 * bitonic_sort - sort via bitonic method
 * @array: int
 * @size: size_t
 * Return: always 0
 */

void bitonic_sort(int *array, size_t size)
{
	int dir = 1;

	if (size < 2 || !array)
		return;

	caller_bitonic(array, 0, size, dir, size);

}

/**
 * caller_bitonic - recursive bitonic function
 * @array: int
 * @start: int
 * @s_size: int
 * @dir: int
 * @f_size: int
 * Return: always 0
 */

void caller_bitonic(int *array, int start, int s_size, int dir, int f_size)
{
	if (s_size > 1)
	{

		int s = s_size / 2;

		printf("Merging [%d/%d] ", s_size, f_size);
		printf(dir == 1 ? "(UP):\n" : "(DOWN):\n");
		print_array2(array, start, start + s_size - 1);

		caller_bitonic(array, start, s, 1, f_size);

		caller_bitonic(array, start + s, s, -1, f_size);

		merger_bitonic(array, start, s_size, dir, f_size);

		printf("Result [%d/%d] ", s_size, f_size);
		printf(dir == 1 ? "(UP):\n" : "(DOWN):\n");
		print_array2(array, start, start + s_size - 1);

	}

}

/**
 * merger_bitonic - merge the bitonic sub arrays
 * @array: int
 * @start: int
 * @s_size: int
 * @dir: int
 * @f_size:int
 * Return: always 0
 */

void merger_bitonic(int *array, int start, int s_size, int dir, int f_size)
{

	if (s_size > 1)
	{
		int s = s_size / 2;
		int i = start;

		while (i < s + start)
		{

			if (dir == 1)
			{
				if (array[i] > array[i + s])
					swap(&array[i], &array[i + s]);
			}

			else
			{
				if (array[i] < array[i + s])
					swap(&array[i], &array[i + s]);
			}

			i++;

		}


		merger_bitonic(array, start, s, dir, f_size);
		merger_bitonic(array, start + s, s, dir, f_size);

	}
}

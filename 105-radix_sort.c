#include <stdlib.h>
#include "sort.h"

void csort2(int *arr, int **buff, int size, int lsd)
{
	int i, j, csize = 10, num;
	int c[10] = {0}, c2[10] = {0};

	for (i = 0; i < size; i++)
	{
		num = arr[i];
		for (j = 0; j < lsd; j++)
			if (j > 0)
				num /= 10;
		num %= 10;
		buff[num][c[num]++] = arr[i];
	}

	for (i = 0, j = 0; i < csize; i++)
	{
		while (c[i] > 0)
		{
			arr[j] = buff[i][c2[i]++];
			c[i]--, j++;
		}
	}

	print_array(arr, size);
}

void csort(int *arr, int size, int lsd)
{
	int c[10] = {0};
	int i, j, num, csize = 10, **buff;

	for (i = 0; i < size; i++)
	{
		num = arr[i];
		for (j = 0; j < lsd; j++)
			if (j > 0)
				num /= 10;
		num %= 10;
		c[num]++;
	}

	if (c[0] == size)
		return;

	buff = malloc(sizeof(int *) * 10);
	if (!buff)
		return;

	for (i = 0; i < csize; i++)
		if (c[i] != 0)
			buff[i] = malloc(sizeof(int) * c[i]);

	csort2(arr, buff, size, lsd);

	csort(arr, size, lsd + 1);

	for (i = 0; i < csize; i++)
		if (c[i] > 0)
			free(buff[i]);
	free(buff);
}

void radix_sort(int *arr, size_t size)
{
	if (size < 2)
		return;
	csort(arr, size, 1);
}


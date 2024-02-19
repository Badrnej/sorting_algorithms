#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void copy(int *s, int *d, int size)
{
	int i;
	for (i = 0; i < size; i++)
		d[i] = s[i];
}

void merge(int *a, int *b, int minL, int maxL, int minR, int maxR)
{
	int i = minL, j = minR, k = minL;

	while (i <= maxL || j <= maxR)
		if (i <= maxL && j <= maxR)
			if (b[i] <= b[j])
				a[k] = b[i], k++, i++;
			else
				a[k] = b[j], k++, j++;
		else if (i > maxL && j <= maxR)
			a[k] = b[j], k++, j++;
		else
			a[k] = b[i], k++, i++;
}

void printcheck(int *a, int r1, int r2)
{
	int i;
	for (i = r1; i <= r2; i++)
	{
		if (i > r1)
			printf(", ");
		printf("%d", a[i]);
	}
	printf("\n");
}

void split(int *a, int *b, int min, int max, int size)
{
	int mid, tmax, minL, maxL, minR, maxR;

	if ((max - min) <= 0)
		return;

	mid = (max + min + 1) / 2;
	tmax = max;
	max = mid - 1;

	minL = min;
	maxL = max;

	split(a, b, min, max, size);

	min = mid;
	max = tmax;

	minR = min;
	maxR = max;

	printf("Merging...\n");
	printf("[left]: ");
	printcheck(a, minL, maxL);

	printf("[right]: ");
	printcheck(a, minR, maxR);

	merge(a, b, minL, maxL, minR, maxR);
	copy(a, b, size);

	printf("[Done]: ");
	printcheck(a, minL, maxR);
}

void merge_sort(int *a, size_t size)
{
	int *b;

	if (size < 2)
		return;

	b = malloc(sizeof(int) * size);
	if (b == NULL)
		return;

	copy(a, b, size);

	split(a, b, 0, size - 1, size);

	free(b);
}


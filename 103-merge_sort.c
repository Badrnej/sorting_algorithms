#include "sort.h"

/**
* p_s - prints sorted sub arrays
* @a: array to be sorted
* @s: starting index
* @e: ending index
* Return: nothing
**/
void p_s(int *a, int s, int e)
{
	int i;

	for (i = s; i < e - 1; i++)
		printf("%d, ", a[i]);
	printf("%d\n", a[i]);
}

/**
* m - function that creates a aux array and merges sorted subarrays
* @a: array to be sorted
* @x: an aux array to be used for merging
* @s: starting index
* @m: middle index
* @e: ending index
* Return: nothing
**/
void m(int *a, int *x, int s, int m, int e)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	p_s(a, s, m);
	printf("[right]: ");
	p_s(a, m, e);

	for (i = s; i < e; i++)
		x[i] = a[i];
	j = s;
	k = m;
	for (i = s; i < e; i++)
	{
		if (j >= m)
			a[i] = x[k++];
		else if (k >= e)
			a[i] = x[j++];
		else if (x[k] < x[j])
			a[i] = x[k++];
		else
			a[i] = x[j++];
	}
	printf("[Done]: ");
	p_s(a, s, e);
}

/**
* m_s_h - divides the array in sub arrays for merge.
* @a: array to be sorted
* @x: an aux array to be used for merging
* @s: starting index
* @e: ending index
* Return: nothing
**/
void m_s_h(int *a, int *x, int s, int e)
{
	int m;

	if (e - 1 <= s)
		return;
	m = s + (e - s) / 2;
	m_s_h(a, x, s, m);
	m_s_h(a, x, m, e);
	m(a, x, s, m, e);
}


/**
* m_s - sorts an array of integers using Merge sort
* @a: array to be sorted
* @s: size of the array
* Return: nothing
**/
void m_s(int *a, size_t s)
{
	int *x;

	if (!a || s < 2)
		return;

	x = malloc(sizeof(int) * s);
	if (x == NULL)
		return;
	m_s_h(a, x, 0, s);
	free(x);
}


#include "sort.h"
#include <stdio.h>

/**
 * _c - this is a calloc function
 * @n: number of elements
 * @s: bit size of each element
 * Return: pointer to memory assignment
 */
void *_c(unsigned int n, unsigned int s)
{
	unsigned int i = 0;
	char *p;

	if (n == 0 || s == 0)
		return (NULL);
	p = malloc(n * s);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < (n * s); i++)
		p[i] = '\0';
	return (p);
}

/**
 * m - make a merge
 * @a: one from start to mid
 * @t: temp array used in merge, was created outside to
 * optimize reducing the system calls
 * @s: first element position
 * @mid: array middle
 * @e: last element position
 **/
void m(int *a, int *t, int s, int mid, int e)
{
	/* sizes and temp arrays */
	int l = mid - s + 1, r = e - mid;
	int *l_a, *r_a;
	/* counters */
	int left, right, i = 0;

	l_a = &t[0];
	r_a = &t[r];
	for (left = 0; left < l; left++)
		l_a[left] = a[s + left];
	for (right = 0; right < r; right++)
		r_a[right] = a[mid + 1 + right];
	left = 0, right = 0, i = s;
	/* merging tmp arrays into main array*/
	while (left < l && right < r)
	{
		if (l_a[left] <= r_a[right])
			a[i] = l_a[left], left++;
		else
			a[i] = r_a[right], right++;
		i++;
	}
	/* merging remaining left array into main array*/
	while (left < l)
		a[i] = l_a[left], left++, i++;
	/* merging remaining right array into main array*/
	while (right < r)
		a[i] = r_a[right], right++, i++;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(l_a, left);
	printf("[right]: ");
	print_array(r_a, right);
	printf("[Done]: ");
	print_array(&a[s], left + right);
}

/**
 * merge_sort_recursive - function that sorts an array of integers
 * in ascending order using the Merge sort algorithm
 * @a: array of integers
 * @t: temp array used in merge, was created outside to
 * optimize reducing the system calls
 * @s: first element position
 * @e: last element position
 * Return: void
 */
void merge_sort_recursive(int *a, int *t, int s, int e)
{
	int mid;

	mid = (s + e) / 2;
	if ((s + e) % 2 == 0)
		mid--;
	if (mid >= s)
	{
		merge_sort_recursive(a, t, s, mid);
		merge_sort_recursive(a, t, mid + 1, e);
		m(a, t, s, mid, e);
	}
}

/**
 * merge_sort - function that sorts an array of integers
 * in ascending order using the Merge sort algorithm
 * @size: size of the list
 * @a: array of integers
 * Return: void
 */
void merge_sort(int *a, size_t size)
{
	int *t;

	if (!a || size < 2)
		return;
	t = _c(size, sizeof(int));
	merge_sort_recursive(a, t, 0, size - 1);
	free(t);
}


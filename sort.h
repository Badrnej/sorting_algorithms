#ifndef SORT_H
#define SORT_H


#include <stddef.h>
#include <stdlib.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Print Functions */

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void print_sorted(int *array, int start, int end);
/* tasks */

/* Sorting Algorithms Functions */

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);


/*Advanced Tasks*/
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

/* helper functions */
size_t size_of_list(listint_t *list);
void swap(int *indx_1, int *indx_2);
int hoarePartition(int *array, int start, int end, size_t size);
void quick_sort_helper(int *array, int start, int end, size_t size);
void merge_sort_helper(int *array, int *aux, int start, int end);
void merging(int *array, int *aux, int start, int mid, int end);
void heapify(int *array, size_t n, size_t i);
void swap_list(listint_t *tmp, listint_t **list);

#endif /* SORT_H */

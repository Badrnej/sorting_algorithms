#include "sort.h"

void merge_sub(int *sub, int *buf, size_t front, size_t mid, size_t back);
void merge_sort_rec(int *sub, int *buf, size_t front, size_t back);
void merge_sort(int *arr, size_t size);

/**
 * merge_sub - Merge two subarrays of an array.
 * @sub: The array containing the two subarrays to merge.
 * @buf: A temporary buffer to store the merged subarrays.
 * @front: Index of the first element of the first subarray.
 * @mid: Index of the last element of the first subarray.
 * @back: Index of the last element of the second subarray.
 *
 * This function merges the two subarrays defined by the range [front, mid) and [mid, back)
 * into a single sorted subarray.
 */
void merge_sub(int *sub, int *buf, size_t front, size_t mid, size_t back)
{
    size_t i, j, k = 0;

    // Printing subarrays for debugging
    printf("Merging...\n[left]: ");
    print_array(sub + front, mid - front);

    printf("[right]: ");
    print_array(sub + mid, back - mid);

    // Merge the two subarrays into the buffer
    for (i = front, j = mid; i < mid && j < back; k++)
        buf[k] = (sub[i] < sub[j]) ? sub[i++] : sub[j++];
    for (; i < mid; i++)
        buf[k++] = sub[i];
    for (; j < back; j++)
        buf[k++] = sub[j];
    for (i = front, k = 0; i < back; i++)
        sub[i] = buf[k++];

    // Printing merged subarray for debugging
    printf("[Done]: ");
    print_array(sub + front, back - front);
}

/**
 * merge_sort_rec - Recursively sort a subarray of integers using merge sort.
 * @sub: The subarray of integers to be sorted.
 * @buf: A temporary buffer for merging subarrays.
 * @front: The index of the first element of the subarray.
 * @back: The index of the last element of the subarray + 1.
 *
 * This function recursively divides the subarray into smaller subarrays until
 * the subarrays are of size 1 or 0, then merges them back together in sorted order.
 */
void merge_sort_rec(int *sub, int *buf, size_t front, size_t back)
{
    size_t mid;

    if (back - front > 1)
    {
        mid = front + (back - front) / 2;
        merge_sort_rec(sub, buf, front, mid);
        merge_sort_rec(sub, buf, mid, back);
        merge_sub(sub, buf, front, mid, back);
    }
}

/**
 * merge_sort - Sort an array of integers in ascending order using merge sort.
 * @arr: The array of integers to be sorted.
 * @size: The size of the array.
 *
 * This function sorts the given array of integers in ascending order using
 * the merge sort algorithm.
 */
void merge_sort(int *arr, size_t size)
{
    int *buf;

    if (arr == NULL || size < 2)
        return;

    buf = malloc(sizeof(int) * size);
    if (buf == NULL)
        return;

    merge_sort_rec(arr, buf, 0, size);

    free(buf);
}

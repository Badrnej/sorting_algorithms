#include "sort.h"


/**
 * bubble_sort - Sorts array of integers in ascending 
 * order using Bubble sort.
 * @array: data to sort
 * @size: size of data
 * Return: No Return
 */
void bubble_sort(int *array, size_t size)
{
  size_t a, b, tmp;

  if (size < 2)
    return;

  for (a = 0; a <= size - 1; a++)
  {
    for (b = 0; b <= size - 2; b++)
    {
      if (array[b] > array[b + 1])
      {
        tmp = array[b];
        array[b] = array[b + 1];
        array[b + 1] = tmp;
        print_array(array, size);
      }
    }
  }
}

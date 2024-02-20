#include "sort.h"

void swap_elements(int *first, int *second);
int lomuto_partition(int *array, size_t size, int start, int end);
void lomuto_quicksort(int *array, size_t size, int start, int end);
void quick_sort(int *array, size_t size);

/**
 * swap_elements - Swaps two integers in an array.
 * @first: The first integer to swap.
 * @second: The second integer to swap.
 */
void swap_elements(int *first, int *second)
{
	int temporary;

	temporary = *first;
	*first = *second;
	*second = temporary;
}

/**
 * lomuto_partition - Orders a subset of an array of integers according to
 *                    the Lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @start: The starting index of the subset to order.
 * @end: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int start, int end)
{
	int *pivot, above, below;

	pivot = array + end;
	for (above = below = start; below < end; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_elements(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_elements(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_quicksort - Implements the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @start: The starting index of the array partition to order.
 * @end: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_quicksort(int *array, size_t size, int start, int end)
{
	int partition_index;

	if (end - start > 0)
	{
		partition_index = lomuto_partition(array, size, start, end);
		lomuto_quicksort(array, size, start, partition_index - 1);
		lomuto_quicksort(array, size, partition_index + 1, end);
	}
}

/**
 * quick_sort - Sorts integers in ascending order
 * @array: An array of integers.
 * @size: The array size.
 *
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_quicksort(array, size, 0, size - 1);
}


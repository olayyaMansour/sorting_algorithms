#include "sort.h"

/**
 * swap_integers - Swaps two integers in an array.
 * @first: The first integer to swap.
 * @second: The second integer to swap.
 */
void swap_integers(int *first, int *second)
{
	int temporary;

	temporary = *first;
	*first = *second;
	*second = temporary;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap operation.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, length = size;
	int is_swapped = 0;

	if (array == NULL || size < 2)
		return;

	while (is_swapped == 0)
	{
		is_swapped = 1;
		for (i = 0; i < length - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_integers(array + i, array + i + 1);
				print_array(array, size);
				is_swapped = 0;
			}
		}
		length--;
	}
}


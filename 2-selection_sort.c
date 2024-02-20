#include "sort.h"

/**
 * swap_elements - Swaps two integers in an array.
 * @element1: The first element swapped.
 * @element2: The second element swapped.
 */
void swap_elements(int *element1, int *element2)
{
	int temporary;

	temporary = *element1;
	*element1 = *element2;
	*element2 = temporary;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min_element;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_element = array + i;
		for (j = i + 1; j < size; j++)
			min_element = (array[j] < *min_element) ? (array + j) : min_element;

		if ((array + i) != min_element)
		{
			swap_elements(array + i, min_element);
			print_array(array, size);
		}
	}
}


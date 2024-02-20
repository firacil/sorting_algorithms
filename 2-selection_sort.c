#include "sort.h"

/**
 * swapper - swap two integers in array
 * @n1: the first number to be swapped
 * @n2: the second number to be swapped
 *
 * Return: Nothing
 */

void swapper(int *n1, int *n2)
{
	int temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

/**
 * selection_sort - sorts an array of integers in ascending order.
 * @array: array to be sorted
 * @size: element size of an array
 *
 */

void selection_sort(int *array, size_t size)
{
	int *sm;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		sm = array + i;
		for (j = i + 1; j < size; j++)
			sm = (array[j] < *sm) ? (array + j) : sm;

		if ((array + i) != sm)
		{
			swapper(array + i, sm);
			print_array(array, size);
		}
	}
}

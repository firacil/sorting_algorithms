#include "sort.h"

/**
 * swapper - swap to elements
 * @e1: element 1
 * @e2: element 2
 * Return: None
 */

void swapper(int *e1, int *e2)
{
	int temp;

	temp = *e1;
	*e1 = *e2;
	*e2 = temp;
}

/**
 * bubble_sort - sorts an array of integers
 * @array: array to be sorted
 * @size: number of elements in array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bub = false;

	if (array == NULL || size < 2)
		return;
	while (bub == false)
	{
		bub = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swapper(array + i, array + i + 1);
				print_array(array, size);
				bub = false;
			}
		}
		len--;
	}

}

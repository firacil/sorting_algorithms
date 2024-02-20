#include "sort.h"

/**
 * swapper - swap two integers
 * @n1: number 1
 * @n2: number 2
 */

void swapper(int *n1, int *n2)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

/**
 * lomuto_partition - Lomuto partiton scheme
 * @array: array to be sorted
 * @l: startiong index of the partiton to be sorted
 * @h: ending index of the partiton to be sorted
 * @size: size of the array
 *
 * Return: index of the pivot
 */

int lomuto_partition(int *array, int l, int h, size_t size)
{
	int pivot = array[h];
	int i = l - 1;
	int j;

	for (j = l; j <= h - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swapper(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[h])
	{
		swapper(&array[i + 1], &array[h]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * q_sort - sorts a partition of an array of int using quick sort
 * @array: Array to be sorted
 * @l: starting index of the parttition
 * @h: ending index of the partition
 * @size: size of the array
 *
 * Return: Nothing
 */

void q_sort(int *array, int l, int h, size_t size)
{
	int pv;

	if (l < h)
	{
		pv = lomuto_partition(array, l, h, size);
		q_sort(array, l, pv - 1, size);
		q_sort(array, pv + 1, h, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the quick sor algortihm
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	q_sort(array, 0, size - 1, size);
}

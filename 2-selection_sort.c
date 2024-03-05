#include "sort.h"
/**
 *selection_sort-  sorts an array of integers
 *in ascending order using the Selection sort algorithm.
 *@array: array to be sorted.
 *@size:the size of the array.
 *
 */
void selection_sort(int *array, size_t size)
{
	int store;
	size_t f = 0, b = size - 1, h;

	if (!array || size)
		return;

	while (f < (size - 1))
	{
		while (b > f)
		{
			if (array[f] < array[b])
				h = b;
			b--;
		}
		if (array[f] > array[h])
		{
			store = array[f];
			array[f] = array[h];
			array[h] = store;
			print_array(array, size);
		}
		f++;
	}
}

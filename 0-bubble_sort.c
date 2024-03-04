#include "sort.h"
/**
 *bubble_sort- sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 *@array: the array to be sorted
 *@size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, n;
	int store;

	if (!array || !size)
		return;

	while (i < size)
	{
		n = 0;
		while (n < size - 1)
		{
			if (array[n + 1] < array[n])
			{
				store = array[n];
				array[n] = array[n + 1];
				array[n + 1] = store;
				print_array(array, size);
			}
			n++;
		}
		i++;
	}
}

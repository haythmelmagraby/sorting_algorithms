#include "sort.h"
/**
 *swap_el- swap elements.
 *@a: array to be sorted.
 *@s: size of the array.
 *@f: first element.
 *@sec: second element.
 */
void swap_el(int *a, size_t s, int *f, int *sec)
{
	if (*f != *sec)
	{
		*f = *sec + *f;
		*sec = *f - *sec;
		*f = *f - *sec;

		print_array((const int *)a, s);
	}
}
/**
 *partition- implement the Lomuto partition scheme
 *@a: array to be sorted.
 *@s: size of the array.
 *@lo: the low index.
 *@hi: the highist index.
 *Return: transition.
 */
size_t partition(int *a, size_t s, ssize_t lo, ssize_t hi)
{
	int tr = lo, st = lo, piv = a[hi];

	while (st < hi)
	{
		if (a[st] < piv)
			swap_el(a, s, &a[st], &a[tr++]);
		st++;
	}
	swap_el(a, s, &a[tr], &a[hi]);
	return (tr);
}
/**
 *quicksort- recursion function to sort partitions result
 *@a: array to be sorted.
 *@s: size of the array.
 *@lo: the low index.
 *@hi: the highist index.
 */
void quicksort(int *a, size_t s, ssize_t lo, ssize_t hi)
{
	size_t p;

	if (lo >= hi || lo < 0)
		return;
	p = partition(a, s, lo, hi);

	quicksort(a, s, lo, p - 1);
	quicksort(a, s, p + 1, hi);
}
/**
 *quick_sort-  sorts an array of integers
 *in ascending order using the Quick sort algorithm
 *@array: array to be sorted.
 *@size: the size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;

	quicksort(array, size, 0, size - 1);
}

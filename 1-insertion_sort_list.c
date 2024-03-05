#include "sort.h"
/**
 * swap_node- to swap nodes
 * @first: the fisrt node to be second
 * @second: second node to be first
 */
void swap_node(listint_t *first, listint_t *second)
{
	if (first->prev)
		first->prev->next = second;
	if (second->next)
		second->next->prev = first;

	first->next = second->next;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
}
/**
 *insertion_sort_list-  sorts a doubly linked list of
 *integers in ascending order using the Insertion sort algorithm
 *@list: list to be sorted
 *
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *c;

	if (!*list || !list || !(*list)->next)
		return;
	i = (*list)->next;
	while (i)
	{
		c = i;
		while (c && c->prev)
		{
			if (c->n > c->prev->n)
				c = c->prev;
			else
			{
				swap_node(c->prev, c);
				if (!c->prev)
					*list = c;
				print_list((const listint_t *) *list);
			}
		}
		i = i->next;
	}
}

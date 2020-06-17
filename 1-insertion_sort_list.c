#include "sort.h"

/**
 * insertion_sort_list - Function that sorts a doubly/
 * linked list in ascending order Insertion sort algorithm
 * @list: Linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *tmp;

	cur = *list;
	if (cur == NULL || cur->next == NULL)
		return;
	cur = cur->next;
	while (cur != NULL)
	{
		tmp = cur;
		cur = cur->next;
		while (tmp->prev && tmp->n < tmp->prev->n)
		{
			tmp->prev->next = tmp->next;
			tmp->next = tmp->prev;
			tmp->prev = tmp->next->prev;
			tmp->next->prev = tmp;
			if (tmp->prev)
				tmp->prev->next = tmp;
			else
				*list = tmp;
			if (tmp->next->next)
				tmp->next->next->prev = tmp->next;
			print_list(*list);
		}
	}
}

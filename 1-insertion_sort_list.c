#include "sort.h"

/**
 * swapper - swap to nodes in a listint_t doubly linked list.
 * @head: a pointer to head of DLL.
 * @n1: fisrt node to be swapped
 * @n2: second node to be swapped
 *
 * Return: nothing
 */

void swapper(listint_t **head, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*head = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending ordr using insert sort algorithm
 * @list: list to be sorted
 *
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = temp)
	{
		temp = i->next;
		insert = i->prev;
		while (insert != NULL && i->n < insert->n)
		{
			swapper(list, &insert, i);
			print_list((const listint_t *)*list);
		}
	}
}

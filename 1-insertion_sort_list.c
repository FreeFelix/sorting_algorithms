#include "sort.h"

/**
 * swap - Swaps two nodes in a doubly linked list.
 * @head: The head node of the list.
 * @node1: The first node to be swapped.
 * @node2: The second node to be swapped.
 *
 * Description:
 * This function swaps two nodes in a doubly linked list.
 * It updates the next and prev pointers of the nodes and
 * adjusts the head pointer if necessary.
 *
 * Return: Void
 */
void swap(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *prev, *next;

	prev = node1->prev;
	next = node2->next;

	if (prev != NULL)
		prev->next = node2;
	else
		*head = node2;
	node1->prev = node2;
	node1->next = next;
	node2->prev = prev;
	node2->next = node1;
	if (next)
		next->prev = node1;
}

/**
 * insertion_sort_list - Sorts a doubly linked list using
 * the insertion sort algorithm.
 * @list: The list to be sorted.
 *
 * Description:
 * This function implements the insertion sort algorithm on a
 * doubly linked list. It iterates through the list, comparing
 * adjacent nodes and swapping them if they are in the wrong order.
 * The process repeats until the entire list is sorted. The function
 * prints the list after each swap.
 *
 * Return: Void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *forw, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (forw = (*list)->next; forw && forw->prev; forw = forw->next)
	{
		for (; forw && forw->prev && forw->n < forw->prev->n;
		     forw = forw->prev)
		{
			tmp = forw->prev;
			swap(list, tmp, forw);
			print_list(*list);
			forw = forw->next;
		}
	}
}


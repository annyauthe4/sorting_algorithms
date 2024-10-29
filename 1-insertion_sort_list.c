#include "sort.h"

/**
  * swap_nodes - Swaps two adjacent nodes in a doubly linked list.
  * @list: Double pointer to the head of the list
  * @node1: Pointer to the first node
  * @node2: Pointer to the second node (next of node1)
  */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;

	node2->prev = node1->prev;
	node1->next = node2->next;

	node2->next = node1;
	node1->prev = node2;

	if (!node2->prev)
		*list = node2;
}

/**
  * insertion_sort_list - Sorts a doubly linked list of integers in ascending
  * order using the Insertion sort algorithm.
  * @list: Double pointer to the head of the list
  */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *insert_pos;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		next = current->next;
		insert_pos = current;

		while (insert_pos->prev && insert_pos->prev->n > insert_pos->n)
		{
			swap_nodes(list, insert_pos->prev, insert_pos);
			print_list(*list);
		}
		current = next;
	}
}

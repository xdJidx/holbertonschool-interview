#include "search.h"

/**
 * node_index - Searches for a value in a skip list within a range.
 * @list: A pointer to the head of the skip list to search in.
 * @current: Pointer to the node where to stop the search.
 * @value: The value to search for.
 *
 * Return: A pointer to the first node where value is located, or NULL if not found.
 */
skiplist_t *node_index(skiplist_t *list, skiplist_t *current, int value)
{
	while (list != current->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}
	return (NULL);
}

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: A pointer to the head of the skip list to search in.
 * @value: The value to search for.
 *
 * Return: A pointer to the first node where value is located, or NULL if not found or list is NULL.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *previous, *current;

	if (list == NULL)
		return (NULL);

	current = list;
	while (current->express != NULL)
	{
		previous = current;
		current = current->express;
		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
		if (current->n >= value)
			break;
		if (current->express == NULL || current->n > value)
			break;
	}

	if (current->express == NULL && current->n < value)
	{
		previous = current;
		while (current->next != NULL)
			current = current->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", previous->index, current->index);
	return (node_index(previous, current, value));
}

#include "search.h"

/* Function prototypes */
skiplist_t *traverse_express_lane(skiplist_t *current, int value);
void print_range(skiplist_t *current);
skiplist_t *traverse_range(skiplist_t *current, skiplist_t *express,
						   int value);
skiplist_t *find_node(skiplist_t *current, int value);

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @head: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: A pointer to the first node where value is located,
 *         or NULL if value is not present in list or if head is NULL
 */
skiplist_t *linear_skip(skiplist_t *head, int value)
{
	if (head == NULL)
		return (NULL);

	skiplist_t *current = head;

	current = traverse_express_lane(current, value);
	print_range(current);
	current = traverse_range(current, current->express, value);
	return (find_node(current, value));
}

/**
 * traverse_express_lane - Traverse the express lane to find a range
 * @current: Pointer to the current node
 * @value: Value to search for
 *
 * Return: Pointer to the node where the value is located or should be located
 */
skiplist_t *traverse_express_lane(skiplist_t *current, int value)
{
	while (current->express != NULL && current->express->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			   current->express->index, current->express->n);
		current = current->express;
	}
	return (current);
}

/**
 * print_range - Print the range where value might be located
 * @current: Pointer to the current node
 */
void print_range(skiplist_t *current)
{
	if (current->express != NULL)
		printf("Value found between indexes [%lu] and [%lu]\n",
			   current->index, current->express->index);
	else
		printf("Value found between indexes [%lu] and [%lu]\n",
			   current->index, current->index);
}

/**
 * traverse_range - Traverse the range to find the exact node
 * @current: Pointer to the current node
 * @express: Pointer to the express node
 * @value: Value to search for
 *
 * Return: Pointer to the node where the value is located or should be located
 */
skiplist_t *traverse_range(skiplist_t *current, skiplist_t *express, int value)
{
	while (current != NULL && current->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			   current->index, current->n);
		if (current == express || express == NULL)
			break;
		current = current->next;
	}
	return (current);
}

/**
 * find_node - Find the node containing the value
 * @current: Pointer to the current node
 * @value: Value to search for
 *
 * Return: Pointer to the node where the value is located, or NULL if not found
 */
skiplist_t *find_node(skiplist_t *current, int value)
{
	if (current != NULL && current->n == value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			   current->index, current->n);
		return (current);
	}
	return (NULL);
}

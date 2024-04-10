#include <stdlib.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (sorted_array_to_avl_recursive(array, 0, size - 1, NULL));
}

/**
 * sorted_array_to_avl_recursive - Recursive helper function to build AVL tree
 * @array: Pointer to the first element of the array
 * @start: Starting index of the subarray
 * @end: Ending index of the subarray
 * @parent: Pointer to the parent node
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl_recursive(int *array, int start, int end,
	avl_t *parent)
{
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	avl_t *root = malloc(sizeof(avl_t));

	if (root == NULL)
		return (NULL);

	root->n = array[mid];
	root->parent = parent;
	root->left = sorted_array_to_avl_recursive(array, start, mid - 1, root);
	root->right = sorted_array_to_avl_recursive(array, mid + 1, end, root);

	return (root);
}

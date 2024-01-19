#include <stdlib.h>
#include "binary_trees.h"


/**
 * heapify - Maintains the Max Heap property after insertion
 * @node: Pointer to the newly inserted node
 * Return: Pointer to the node after maintaining the Max Heap property
 */
heap_t *heapify(heap_t *node)
{
    int temp;
    heap_t *largest = node;

    if (node->left && node->left->n > largest->n)
        largest = node->left;

    if (node->right && node->right->n > largest->n)
        largest = node->right;

    if (largest != node)
    {
        temp = node->n;
        node->n = largest->n;
        largest->n = temp;
        return heapify(largest);
    }

    return node;
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *current;

    if (!root)
        return NULL;

    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return NULL;

    if (!*root)
    {
        *root = new_node;
        return new_node;
    }

    /* Insert as leftmost available spot in the last level */
    for (current = *root; current->left && current->right; )
    {
        if (!current->left->left || !current->left->right)
            current = current->left;
        else
            current = current->right;
    }

    if (!current->left)
        current->left = new_node;
    else
        current->right = new_node;

    new_node->parent = current;

    /* Maintain Max Heap property */
    return heapify(new_node);
}

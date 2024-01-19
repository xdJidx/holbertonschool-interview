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

    while (node->parent && node->n > node->parent->n)
    {
        temp = node->n;
        node->n = node->parent->n;
        node->parent->n = temp;
        node = node->parent;
    }

    return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node;

    if (!root)
        return (NULL);

    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    if (!*root)
    {
        *root = new_node;
        return (new_node);
    }

    if ((*root)->left == NULL)
    {
        (*root)->left = new_node;
        new_node->parent = *root;
    }
    else if ((*root)->right == NULL)
    {
        (*root)->right = new_node;
        new_node->parent = *root;
    }
    else
    {
        (*root)->left->left = new_node;
        new_node->parent = (*root)->left;
    }

    return (heapify(new_node));
}
#include <stdio.h>
#include <stdlib.h>

/**
 * struct binary_tree_s - Binary tree node
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s heap_t;

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const heap_t *tree)
{
    if (!tree)
        return (0);

    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * heapify - Heapify the tree to maintain Max Heap property
 * @root: Pointer to the root of the tree
 */
void heapify(heap_t *root)
{
    heap_t *largest = root;
    heap_t *left = root->left;
    heap_t *right = root->right;

    if (left && left->n > largest->n)
        largest = left;

    if (right && right->n > largest->n)
        largest = right;

    if (largest != root)
    {
        int temp = root->n;
        root->n = largest->n;
        largest->n = temp;

        heapify(largest);
    }
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;

    new_node = malloc(sizeof(heap_t));

    if (!new_node)
        return (NULL);

    new_node->n = value;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;

    if (!*root)
    {
        *root = new_node;
        return (new_node);
    }

    parent = *root;

    while (parent->left && parent->right)
    {
        if (binary_tree_size(parent->left) <= binary_tree_size(parent->right))
            parent = parent->left;
        else
            parent = parent->right;
    }

    if (!parent->left)
        parent->left = new_node;
    else
        parent->right = new_node;

    new_node->parent = parent;

    while (new_node->parent && new_node->n > new_node->parent->n)
    {
        int temp = new_node->parent->n;
        new_node->parent->n = new_node->n;
        new_node->n = temp;
        new_node = new_node->parent;
    }

    heapify(*root);

    return (new_node);
}
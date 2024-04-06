#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 *
 * This function checks if a binary tree is full, which means that every node
 * in the tree has either 0 or 2 children. If the tree is empty (tree is NULL),
 * the function returns 0. If the tree is full, the function returns 1. If the
 * tree is not full, the function returns 0.
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	if (tree->right && tree->left)
		return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));

	return (0);
}

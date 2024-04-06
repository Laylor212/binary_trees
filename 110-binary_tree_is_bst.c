#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 *
 * This function checks if a binary tree is a valid Binary Search Tree (BST).
 * A BST is a binary tree where the value of each node is greater than or equal
 * to the values of all the nodes in its left subtree and less than or equal to
 * the values of all the nodes in its right subtree.
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (btib_helper(tree, INT_MIN, INT_MAX));
}

/**
 * btib_helper - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 * @min: Lower bound of checked nodes
 * @max: Upper bound of checked nodes
 *
 * This function is a helper function that checks if a binary tree is a valid
 * Binary Search Tree (BST). It recursively checks if the value of each node is
 * within the specified range of the minimum and maximum values. If the value
 * of the current node is outside the range, the function returns 0. If the
 * current node is NULL, the function returns 1. Otherwise, it recursively
 * calls itself on the left and right subtrees, updating the range accordingly.
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int btib_helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (btib_helper(tree->left, min, tree->n - 1) &&
		btib_helper(tree->right, tree->n + 1, max));
}

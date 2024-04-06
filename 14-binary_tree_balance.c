#include "binary_trees.h"

/**
 * binary_tree_height_b - Measures the height of a binary tree.
 *
 * This function calculates the height of a binary tree by recursively
 * traversing the tree and counting the number of levels. The height of
 * a binary tree is defined as the number of edges in the longest path
 * from the root to a leaf node.
 *
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: The height of the binary tree as a size_t value.
 *         If the tree is empty (NULL), 0 is returned.
 */
size_t binary_tree_height_b(const binary_tree_t *tree)
{
	size_t l = 0;
	size_t r = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			l = tree->left ? 1 + binary_tree_height_b(tree->left) : 1;
			r = tree->right ? 1 + binary_tree_height_b(tree->right) : 1;
		}
		return ((l > r) ? l : r);
	}
}

/**
 * binary_tree_balance - Measures balance factor of a binary tree
 * @tree: A pointer to the root node of the binary tree.
 *
 * This function calculates the balance factor of a binary tree by subtracting
 * the height of the right subtree from the height of the left subtree. The
 * balance factor of a binary tree is defined as the difference between the
 * heights of its left and right subtrees. A balance factor of 0 indicates a
 * balanced tree, a positive balance factor indicates a left-heavy tree, and
 * a negative balance factor indicates a right-heavy tree.
 *
 * Return: The balance factor of the binary tree as an integer value.
 *         If the tree is empty (NULL), 0 is returned.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int right = 0, left = 0, total = 0;

	if (tree)
	{
		left = ((int)binary_tree_height_b(tree->left));
		right = ((int)binary_tree_height_b(tree->right));
		total = left - right;
	}
	return (total);
}

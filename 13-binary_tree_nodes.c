#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes in a binary tree
 * @tree: tree to count the nodes from
 *
 * Return: number of nodes
 *         0 if tree is NULL or if tree has no children
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);

	return (binary_tree_size(tree) - binary_tree_leaves(tree));
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size from
 *
 * This function recursively calculates the size of a binary tree by summing
 * the number of nodes in the left subtree, the number of nodes in the right
 * subtree, and adding 1 for the current node. The size of a binary tree is
 * defined as the total number of nodes in the tree.
 *
 * Return: size of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: tree to count the leaves from
 *
 * This function recursively counts the number of leaves in a binary tree.
 * A leaf node is a node that has no children. The function checks if the
 * tree is NULL, and if so, returns 0. If the tree has no children, it
 * returns 1. Otherwise, it recursively calls itself on the left and right
 * subtrees and returns the sum of the leaf counts from both subtrees.
 *
 * Return: number of leaves in the tree
 *         0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}

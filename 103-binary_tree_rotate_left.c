#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Function that rotates the binary tree to the left.
 * @tree: The root node of the tree.
 *
 * Description: This function performs a left rotation on the binary tree,
 *              where the given tree becomes the right child of its left child.
 *              The left child of the tree becomes the new root of the subtree.
 *
 * Return: Pointer to the new root node of the rotated tree.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	pivot = tree->right;
	tree->right = pivot->left;
	if (pivot->left != NULL)
	{
		pivot->left->parent = tree;
	}
	pivot->left = tree;
	pivot->parent = tree->parent;
	tree->parent = pivot;
	return (pivot);
}

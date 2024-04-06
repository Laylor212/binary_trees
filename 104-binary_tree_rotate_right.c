#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Function that rotates binary tree to the right.
 * @tree: The root node of the tree.
 *
 * Description:	This function rotates the binary tree to the right by 
 * 				performing a right rotation on the given tree. It takes 
 * 				the root node of the tree as input and returns the pointer 
 * 				to the new root node after the rotation.
 *
 * Return: Pointer to the new root node of the rotated tree.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	pivot = tree->left;
	tree->left = pivot->right;
	if (pivot->right != NULL)
	{
		pivot->right->parent = tree;
	}
	pivot->right = tree;
	pivot->parent = tree->parent;
	tree->parent = pivot;
	return (pivot);
}

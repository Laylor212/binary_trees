#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverses binary tree using level-order traversal.
 * @tree: Pointer to the binary tree to traverse.
 * @func: Pointer to a function to call for each node.
 *
 * Description: This function traverses a binary tree using level-order 
 * 				traversal, starting from the root node and visiting each 
 * 				level from left to right. It calls the specified function 
 * 				or each visited node. The function takes an integer argument,
 * 				which is the value of the node. If the tree or the function 
 * 				pointer is NULL, the function does nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level, maxlevel;

	if (!tree || !func)
		return;

	maxlevel = binary_tree_height(tree) + 1;

	for (level = 1; level <= maxlevel; level++)
		btlo_helper(tree, func, level);
}

/**
 * btlo_helper - Goes through a binary tree using post-order traversal.
 * @tree: Pointer to the binary tree to traverse.
 * @func: Pointer to a function to call for each node.
 * @level: The level of the tree to call func upon.
 *
 * Description: This function recursively traverses a binary tree using 
 * 				post-order traversal. If the level is 1, it calls the 
 * 				specified function on the value of the node. Otherwise, 
 * 				it recursively calls itself on the left and right subtrees 
 * 				with level - 1. If the tree or the function pointer is NULL, 
 * 				the function does nothing.
 */
void btlo_helper(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 1)
		func(tree->n);
	else
	{
		btlo_helper(tree->left, func, level - 1);
		btlo_helper(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to measure the height of
 *
 * Return: height of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

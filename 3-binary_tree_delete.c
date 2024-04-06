#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: a pointer to the root node of the tree to delete
 *
 * Description:	This function recursively deletes an entire binary tree 
 * 				starting from the given root node. If the tree is NULL, 
 * 				the function does nothing. The function first deletes 
 * 				the right subtree, then the left subtree, and finally frees 
 * 				the memory of the root node.
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;
	binary_tree_delete(tree->right);
	binary_tree_delete(tree->left);
	free(tree);
}

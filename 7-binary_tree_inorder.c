#include "binary_trees.h"


/**
 * binary_tree_inorder - goes through th tree and calls a func inorder
 * @tree: node of tree
 * @func: func to call
 * Return: void
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}

#include "binary_trees.h"


/**
 * binary_tree_postorder - goes through th tree and calls a func postorder
 * @tree: node of tree
 * @func: func to call
 * Return: void
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}

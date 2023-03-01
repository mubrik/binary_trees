#include "binary_trees.h"


/**
 * binary_tree_preorder - goes through th tree and calls a func preorderly
 * @tree: node of tree
 * @func: func to call
 * Return: void
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}

#include "binary_trees.h"


/**
 * binary_tree_is_full - checks if a b_tree is full 2/0 nodes
 * @tree: node of tree
 * Return: void
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) & binary_tree_is_full(tree->right));
	return (0);
}

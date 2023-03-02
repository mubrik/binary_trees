#include "binary_trees.h"


/**
 * binary_tree_nodes - counts the nodes with a child in a binary tree
 * @tree: node of tree
 * Return: void
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (binary_tree_is_leaf(tree))
		return (0);

	return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}

#include "binary_trees.h"

/**
 * _b_depth - Measures the depth of a binary tree
 * @node: Pointer to the node to measures the depth
 * Return: The depth of the tree starting at @node
 */
size_t _b_depth(const binary_tree_t *node)
{
	if (!node)
		return (0);
	return (1 + _b_depth(node->parent));
}

/**
 * binary_tree_depth - measures the depth of a b_tree
 * @tree: node of tree
 * Return: void
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || !tree->parent)
		return (0);
	return (_b_depth(tree->parent));
}

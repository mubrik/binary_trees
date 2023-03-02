#include "binary_trees.h"

/**
 * _b_size - Measures the size of a binary tree
 * @node: Pointer to the node to measures the size
 * Return: The size of the tree starting at @node
 */
size_t _b_size(const binary_tree_t *node)
{
	size_t height_l = 0, height_r = 0;

	height_l = node->left ? 1 + _b_size(node->left) : 0;
	height_r = node->right ? 1 + _b_size(node->right) : 0;
	return (height_l + height_r);
}

/**
 * binary_tree_size - measures the size of a b_tree
 * @tree: node of tree
 * Return: void
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + _b_size(tree));
}

#include "binary_trees.h"

/**
 * _b_height - Measures the height of a binary tree
 * @node: Pointer to the node to measures the height
 * Return: The height of the tree starting at @node
 */
size_t _b_height(const binary_tree_t *node)
{
	size_t height_l = 0, height_r = 0;

	height_l = node->left ? 1 + _b_height(node->left) : 0;
	height_r = node->right ? 1 + _b_height(node->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_height - measures the height of a b_tree
 * @tree: node of tree
 * Return: void
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (_b_height(tree));
}

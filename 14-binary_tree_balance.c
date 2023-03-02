#include "binary_trees.h"


/**
 * _bd_height - Measures the height of a binary tree
 * @node: Pointer to the node to measures the height
 * Return: The height of the tree starting at @node
 */
size_t _bd_height(const binary_tree_t *node)
{
	size_t height_l = 0, height_r = 0;

	if (!node)
		return (0);

	height_l = node->left ? 1 + _bd_height(node->left) : 0;
	height_r = node->right ? 1 + _bd_height(node->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_balance - measures the balance of a b_tree
 * @tree: node of tree
 * Return: void
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (!tree)
		return (0);

	l = tree->left ? 1 + _bd_height(tree->left) : 0;
	r = tree->right ? 1 + _bd_height(tree->right) : 0;
	return (l - r);
}

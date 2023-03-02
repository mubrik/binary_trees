#include "binary_trees.h"

/**
 * _bdt_height - Measures the height of a binary tree
 * @node: Pointer to the node to measures the height
 * Return: The height of the tree starting at @node
 */
size_t _bdt_height(const binary_tree_t *node)
{
	size_t height_l = 0, height_r = 0;

	if (!node)
		return (0);

	height_l = node->left ? 1 + _bdt_height(node->left) : 0;
	height_r = node->right ? 1 + _bdt_height(node->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * _bdt_perfect - checks if a b_tree is perfect
 * @tree: node of tree
 * Return: void
 */
int _bdt_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (!tree->left || !tree->right)
		return (0);

	return (
		binary_tree_is_perfect(tree->left) & binary_tree_is_perfect(tree->right));

}

/**
 * binary_tree_is_perfect - checks if a b_tree is perfect
 * @tree: node of tree
 * Return: void
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (!tree)
		return (0);
	if (!_bdt_perfect(tree))
		return (0);

	l = tree->left ? 1 + _bdt_height(tree->left) : 0;
	r = tree->right ? 1 + _bdt_height(tree->right) : 0;

	if (l - r == 0)
		return (1);
	return (0);
}

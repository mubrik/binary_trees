#include "binary_trees.h"


/**
 * binary_tree_is_perfect - checks if a b_tree is perfect
 * @tree: node of tree
 * Return: void
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
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

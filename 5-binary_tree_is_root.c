#include "binary_trees.h"


/**
 * binary_tree_is_root - checks if node is a root node
 * @node: node of tree
 * Return: 1 if root, 0 else
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (!node->parent)
		return (1);
	return (0);
}

#include "binary_trees.h"


/**
 * binary_tree_sibling - finds the sibliing of a node
 * @node: node of tree
 * Return: node or null
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	return (node->parent->right == node ?
		node->parent->left : node->parent->right);
}

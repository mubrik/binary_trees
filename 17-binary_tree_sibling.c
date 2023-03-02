#include "binary_trees.h"


/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: node of tree
 * Return: node or null
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *dad = NULL;

	if (!node || !node->parent || !node->parent->parent)
		return (NULL);
	dad = node->parent;

	return (dad->parent->right == dad ? dad->parent->left : dad->parent->right);
}

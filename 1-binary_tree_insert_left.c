#include "binary_trees.h"

/**
 * binary_tree_insert_left - adds a node to the left of a node
 *
 * @parent: parent of node
 * @value: value of node
 *
 * Return: the node or null
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	if (!parent)
		return (node);
	/* create node */
	node = binary_tree_node(parent, value);
	if (!node)
		return (node);
	/* make old parent left new nodes left */
	if (parent->left)
		parent->left->parent = node, node->left = parent->left;
	parent->left = node;

	return (node);
}

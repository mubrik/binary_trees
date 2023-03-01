#include "binary_trees.h"

/**
 * binary_tree_insert_right - adds a node to the right of a node
 *
 * @parent: parent of node
 * @value: value of node
 *
 * Return: the node or null
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	if (!parent)
		return (node);
	/* create node */
	node = binary_tree_node(parent, value);
	if (!node)
		return (node);
	/* make old parent right new nodes right */
	if (parent->right)
		parent->right->parent = node, node->right = parent->right;
	parent->right = node;

	return (node);
}

#include "binary_trees.h"

/**
 * binary_tree_node - adds a node to the binary tree
 *
 * @parent: parent of node
 * @value: value of node
 *
 * Return: the node or null
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	/* create node */
	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (node);

	/* assign */
	node->parent = parent ? parent : NULL;
	node->n = value, node->left = node->right = NULL;

	return (node);
}

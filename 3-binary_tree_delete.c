#include "binary_trees.h"

/**
 * _remove_node - recursively free nodes
 * @node: node
 * Return: void
 */
void _remove_node(binary_tree_t *node)
{
	if (!node)
		return;
	_remove_node(node->left);
	_remove_node(node->right);
	free(node);
}

/**
 * binary_tree_delete - deletes and frees tree
 * @tree: parent of node
 * Return: void
 */
void binary_tree_delete(binary_tree_t *tree)
{

	if (!tree)
		return;
	_remove_node(tree);
}

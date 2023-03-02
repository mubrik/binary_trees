#include "../binary_trees.h"

#include <stdio.h>
#include <limits.h>

/**
 * print_status - debug, prints a sttus message
 * @num: status number
 * @status: status msg
 *
 * Return: void
 */
void print_status(int num, char *status)
{
	printf("\n----------------------------------");
	if (!num)
	{
		printf("\n --- %s Test successful --- \n", status);
		printf("----------------------------------\n");
		return;
	}
	else if (num == 1)
	{
		printf("\n --- %s Test unsuccessful, node is null --- \n", status);
		return;
	}

	printf("\n --- %s Test unsuccessful, malloc err --- \n", status);
}

/**
 * print_test_st - debug, prints a sttus message
 * @status: status msg
 *
 * Return: void
 */
void print_test_st(char *status)
{
	printf("--------------------------------------------\n");
	printf("------ starting %s -------\n", status);
	printf("--------------------------------------------\n");
}

/**
 * _recursive_run - recursively runs a function on nodes
 * @tree: node
 * Return: void
 */
void _recursive_run(binary_tree_t *node, void (*f)(binary_tree_t*))
{
	if (!node || !f)
		return;
	_recursive_run(node->left, f);
	_recursive_run(node->right, f);
	f(node);
}

/**
 * _is_leaf_wrapper - checks if leaf
 * @tree: node
 * Return: void
 */
void _is_leaf_wrapper(binary_tree_t *node)
{
	if (!node)
		return;
	printf("Is %d a leaf: %d\n", node->n, binary_tree_is_leaf(node));
}

/**
 * _is_root_wrapper - checks if root
 * @tree: node
 * Return: void
 */
void _is_root_wrapper(binary_tree_t *node)
{
	if (!node)
		return;
	printf("Is %d root: %d\n", node->n, binary_tree_is_root(node));
}

/**
 * _height_wrapper - checks if root
 * @tree: node
 * Return: void
 */
void _height_wrapper(binary_tree_t *node)
{
	if (!node)
		return;
	printf("Height from %d: %lu\n", node->n, binary_tree_height(node));
}

/**
 * _size_wrapper - checks if root
 * @tree: node
 * Return: void
 */
void _size_wrapper(binary_tree_t *node)
{
	if (!node)
		return;
	printf("Size from %d: %lu\n", node->n, binary_tree_size(node));
}

/**
 * _depth_wrapper - checks if root
 * @tree: node
 * Return: void
 */
void _depth_wrapper(binary_tree_t *node)
{
	if (!node)
		return;
	printf("Depth from %d: %lu\n", node->n, binary_tree_depth(node));
}

/**
 * _leaves_wrapper - checks if leaves
 * @tree: node
 * Return: void
 */
void _leaves_wrapper(binary_tree_t *node)
{
	if (!node)
		return;
	printf("Leaves from %d: %lu\n", node->n, binary_tree_leaves(node));
}

/**
 * _nodes_wrapper - checks if nodes
 * @tree: node
 * Return: void
 */
void _nodes_wrapper(binary_tree_t *node)
{
	if (!node)
		return;
	printf("Nodes from %d: %lu\n", node->n, binary_tree_nodes(node));
}

/**
 * _balance_wrapper - checks if nodes
 * @tree: node
 * Return: void
 */
void _balance_wrapper(binary_tree_t *node)
{
	if (!node)
		return;
	printf("Balance from %d: %+d\n", node->n, binary_tree_balance(node));
}

/**
 * _full_wrapper - checks if nodes
 * @tree: node
 * Return: void
 */
void _full_wrapper(binary_tree_t *node)
{
	if (!node)
		return;
	printf("Full from %d: %d\n", node->n, binary_tree_is_full(node));
}

/**
 * _perfect_wrapper - checks if nodes
 * @tree: node
 * Return: void
 */
void _perfect_wrapper(binary_tree_t *node)
{
	if (!node)
		return;
	printf("Perfect from %d: %d\n", node->n, binary_tree_is_perfect(node));
}

/**
 * print_num - Prints a number
 * @n: Number to be printed
 */
void print_num(int n)
{
	printf("%d\n", n);
}


/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root;
	int pr_status;
	print_test_st("Test 0 - Task 0");
	root = binary_tree_node(NULL, 555);

	root->left = binary_tree_node(root, 12);
	root->left->left = binary_tree_node(root->left, 222);
	root->left->right = binary_tree_node(root->left, 16);

	root->right = binary_tree_node(root, 402);
	root->right->left = binary_tree_node(root->right, 256);
	root->right->right = binary_tree_node(root->right, 512);

	pr_status = binary_test_print(root);
	print_status(pr_status, "Test 0");
	/* free(root); */

	/* root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	binary_test_print(root); */
	print_test_st("Test 1 - Task 1");
	printf("\n");
	binary_tree_insert_left(root->right, 197);
	binary_tree_insert_left(root, 54);
	/* binary_test_print(root); */

	pr_status = binary_test_print(root);
	print_status(pr_status, "Test 1");
	/* free(root); */

	/* root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 472);
	binary_test_print(root); */
	print_test_st("Test 2 - Task 2");
	printf("\n");
	binary_tree_insert_right(root->left, 94);
	binary_tree_insert_right(root, 128);
	/* binary_test_print(root); */

	pr_status = binary_test_print(root);
	print_status(pr_status, "Test 2");

	print_test_st("Test 3 - Task 4");
	_recursive_run(root, _is_leaf_wrapper);
	print_status(0, "Test 3 is leaf");

	print_test_st("Test 4 - Task 5");
	_recursive_run(root, _is_root_wrapper);
	print_status(0, "Test 4 is root");

	print_test_st("Test 5 - Task 6");
	binary_test_print(root);
	binary_tree_preorder(root, print_num);
	print_status(0, "Test 5 preorder traversal");

	print_test_st("Test 6 - Task 7");
	binary_test_print(root);
	binary_tree_inorder(root, print_num);
	print_status(0, "Test 6 inorder traversal");

	print_test_st("Test 7 - Task 8");
	binary_test_print(root);
	binary_tree_postorder(root, print_num);
	print_status(0, "Test 7 postorder traversal");

	print_test_st("Test 8 - Task 9");
	binary_test_print(root);
	_recursive_run(root, _height_wrapper);
	print_status(0, "Test 8 height");

	print_test_st("Test 9 - Task 10");
	binary_test_print(root);
	_recursive_run(root, _depth_wrapper);
	print_status(0, "Test 9 depth");

	print_test_st("Test 10 - Task 11");
	binary_test_print(root);
	_recursive_run(root, _size_wrapper);
	print_status(0, "Test 10 size");

	print_test_st("Test 11 - Task 12");
	binary_test_print(root);
	_recursive_run(root, _leaves_wrapper);
	print_status(0, "Test 11 size");

	print_test_st("Test 12 - Task 13");
	binary_test_print(root);
	_recursive_run(root, _nodes_wrapper);
	print_status(0, "Test 12 size");

	print_test_st("Test 13 - Task 14");
	binary_test_print(root);
	_recursive_run(root, _balance_wrapper);
	/* printf("Balance %d\n", binary_tree_balance(root->right->right->left)); */
	print_status(0, "Test 13 size");

	print_test_st("Test 14 - Task 15");
	binary_test_print(root);
	_recursive_run(root, _full_wrapper);
	print_status(0, "Test 14 size");

	print_test_st("Test 15 - Task 16");
	binary_test_print(root);
	_recursive_run(root, _perfect_wrapper);
	print_status(0, "Test 15 size");

	print_test_st("Test 4 - Task 3");
	binary_tree_delete(root);
	print_status(0, "Test 4, free test check valgrind");


	return (0);
}

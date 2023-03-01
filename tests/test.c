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
	binary_tree_insert_left(root->right, 128);
	binary_tree_insert_left(root, 54);
	/* binary_test_print(root); */

	pr_status = binary_test_print(root);
	print_status(pr_status, "Test 1");
	/* free(root); */

	/* root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	binary_test_print(root); */
	print_test_st("Test 2 - Task 2");
	printf("\n");
	binary_tree_insert_right(root->left, 54);
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

	print_test_st("Test 4 - Task 3");
	binary_tree_delete(root);
	print_status(0, "Test 4, free test check valgrind");


	return (0);
}

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
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root;
	int pr_status;

	root = binary_tree_node(NULL, 555);

	root->left = binary_tree_node(root, 12);
	root->left->left = binary_tree_node(root->left, 222);
	root->left->right = binary_tree_node(root->left, 16);

	root->right = binary_tree_node(root, 402);
	root->right->left = binary_tree_node(root->right, 256);
	root->right->right = binary_tree_node(root->right, 512);

	pr_status = binary_test_print(root);
	print_status(pr_status, "Test 0");

	return (0);
}

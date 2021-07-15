#include "ft_btree.h"

// // REMOVE
// #include <stdlib.h>
// #include <stdio.h>

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	btree_level_count(t_btree *root)
{
	int	left;
	int	right;

	if (!root)
		return (0);
	left = btree_level_count(root->left);
	right = btree_level_count(root->right);
	return (ft_max(left, right) + 1);
}

// t_btree	*btree_create_node(void *item)
// {
// 	t_btree	*btree;

// 	btree = malloc(sizeof(t_btree));
// 	btree->item = item;
// 	btree->left = 0;
// 	btree->right = 0;
// 	return (btree);
// }

// int	main(void)
// {
// 	t_btree	*root;
// 	t_btree	*left;
// 	t_btree	*right;
// 	t_btree	*leftleft;
// 	t_btree	*leftright;

// 	root = btree_create_node("works");
// 	left = btree_create_node("world");
// 	leftleft = btree_create_node("hello");
// 	leftright = btree_create_node("it");
// 	right = btree_create_node("!");
// 	root->left = left;
// 	root->right = right;
// 	left->left = leftleft;
// 	left->right = leftright;

// 	printf("3 = %d\n", btree_level_count(root));
// 	printf("2 = %d\n", btree_level_count(left));
// 	printf("1 = %d\n", btree_level_count(leftleft));
// 	printf("0 = %d\n", btree_level_count(0));
// 	return (0);
// }
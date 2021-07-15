#include "ft_btree.h"

// // REMOVE
// #include <stdlib.h>
// #include <stdio.h>

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	btree_apply_suffix(root->left, applyf);
	btree_apply_suffix(root->right, applyf);
	applyf(root->item);
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

// void	ft_print(void *item)
// {
// 	printf("%s\n", (char *) item);
// }

// int	main(void)
// {
// 	t_btree	*root;
// 	t_btree	*left;
// 	t_btree	*right;
// 	t_btree	*leftleft;
// 	t_btree	*leftright;

// 	root = btree_create_node("!");
// 	left = btree_create_node("it");
// 	leftleft = btree_create_node("hello");
// 	leftright = btree_create_node("world");
// 	right = btree_create_node("works");
// 	root->left = left;
// 	root->right = right;
// 	left->left = leftleft;
// 	left->right = leftright;
// 	btree_apply_suffix(root, ft_print);
// 	return (0);
// }

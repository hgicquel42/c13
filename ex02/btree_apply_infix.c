#include "ft_btree.h"

// // REMOVE
// #include <stdlib.h>
// #include <stdio.h>

void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	btree_apply_infix(root->left, applyf);
	applyf(root->item);
	btree_apply_infix(root->right, applyf);
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

// 	root = btree_create_node("works");
// 	left = btree_create_node("world");
// 	leftleft = btree_create_node("hello");
// 	leftright = btree_create_node("it");
// 	right = btree_create_node("!");
// 	root->left = left;
// 	root->right = right;
// 	left->left = leftleft;
// 	left->right = leftright;
// 	btree_apply_infix(root, ft_print);
// 	return (0);
// }

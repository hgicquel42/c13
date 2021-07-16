#include "ft_btree.h"

// // REMOVE
// #include <stdlib.h>
// #include <stdio.h>

void	btree_apply_to_level(
	t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first),
	int current_level,
	int is_first
)
{
	if (!root)
		return ;
	applyf(root->item, current_level, is_first);
	btree_apply_to_level(
		root->left, applyf,
		current_level + 1, is_first);
	btree_apply_to_level(
		root->right, applyf,
		current_level + 1,
		is_first && !root->left);
}

void	btree_apply_by_level(
	t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first)
)
{
	btree_apply_to_level(root, applyf, 0, 1);
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

// void	ft_print(void *item, int current_level, int is_first)
// {
// 	printf("item = %s, level = %d, first = %d\n", 
// 		(char *) item, current_level, is_first);
// }

// int	main(void)
// {
// 	t_btree	*root;

// 	root = btree_create_node("hello");
// 	root->left = btree_create_node("world");
// 	root->left->left = btree_create_node("it");
// 	root->left->right = btree_create_node("works");
// 	root->right = btree_create_node("!");
// 	root->right->right = btree_create_node(";)");

// 	btree_apply_by_level(root, ft_print);
// 	return (0);
// }
#include "ft_btree.h"

// //REMOVE
// #include <unistd.h>
// #include <stdlib.h>
// #include <stdio.h>

void	btree_insert_data(
	t_btree **root,
	void *item,
	int (*cmpf)(void *, void *)
)
{
	if (!root || !*root)
	{
		if (root)
			*root = btree_create_node(item);
		return ;
	}
	if (cmpf((*root)->item, item) < 0)
		btree_insert_data(&((*root)->left), item, cmpf);
	else
		btree_insert_data(&((*root)->right), item, cmpf);
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

// void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
// {
// 	if (!root)
// 		return ;
// 	btree_apply_infix(root->left, applyf);
// 	applyf(root->item);
// 	btree_apply_infix(root->right, applyf);
// }

// int	ft_strcmp(char *a, char *b)
// {
// 	while (*a && *a == *b)
// 		a++, b++;
// 	return (*a - *b);
// }

// int	ft_cmp(void *a, void *b)
// {
// 	return (ft_strcmp((char *) a, (char *) b));
// }

// void	ft_print(void *item)
// {
// 	printf("%s\n", (char *) item);
// }

// int	main(void)
// {
// 	t_btree	**root;

// 	root = malloc(sizeof(t_btree *));
// 	*root = 0;
// 	btree_insert_data(root, "ccc", &ft_cmp);
// 	btree_insert_data(root, "bbb", &ft_cmp);
// 	btree_insert_data(root, "aaa", &ft_cmp);
// 	btree_insert_data(root, "bcc", &ft_cmp);
// 	btree_insert_data(root, "aab", &ft_cmp);
// 	btree_insert_data(root, "cba", &ft_cmp);
// 	btree_apply_infix(*root, &ft_print);
// 	return (0);
// }

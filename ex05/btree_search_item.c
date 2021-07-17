#include "ft_btree.h"

// // REMOVE
// #include <stdlib.h>
// #include <stdio.h>

void	*btree_search_item(
	t_btree *root,
	void *data_ref,
	int (*cmpf)(void *, void *)
)
{
	void	*left;
	void	*right;

	if (!root)
		return (0);
	left = btree_search_item(root->left, data_ref, cmpf);
	if (left)
		return (left);
	if (!cmpf(root->item, data_ref))
		return (root->item);
	right = btree_search_item(root->right, data_ref, cmpf);
	if (right)
		return (right);
	return (0);
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
// 	printf("%d\n", btree_search_item(root, "hello", ft_cmp) == leftleft->item);
// 	return (0);
// }

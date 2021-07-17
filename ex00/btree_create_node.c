#include "ft_btree.h"
#include <stdlib.h>

// //REMOVE
// #include <stdio.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*btree;

	btree = malloc(sizeof(t_btree));
	if (!btree)
		return (0);
	btree->item = item;
	btree->left = 0;
	btree->right = 0;
	return (btree);
}

// int	main(void)
// {
// 	t_btree	*btree;

// 	btree = btree_create_node("hello");
// 	printf("%d\n", btree->left == 0);
// 	printf("%d\n", btree->right == 0);
// 	printf("%s\n", (char *) btree->item);
// 	return (0);
// }

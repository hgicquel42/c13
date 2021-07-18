#include "ft_btree.h"
#include <stdlib.h>

// // REMOVE
// #include <stdio.h>
// #include <unistd.h>

int	g_level;

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

void	btree_apply_to_level(
	t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first),
	int current_level,
	int	*levels
)
{
	if (!root)
		return ;
	if (current_level > g_level)
		return ;
	if (current_level == g_level)
	{
		applyf(root->item, current_level, levels[current_level]);
		levels[current_level] = 0;
		return ;
	}
	btree_apply_to_level(
		root->left, applyf,
		current_level + 1,
		levels);
	btree_apply_to_level(
		root->right, applyf,
		current_level + 1,
		levels);
}

void	btree_apply_by_level(
	t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first)
)
{
	int	level;
	int	count;
	int	*levels;

	level = 0;
	count = btree_level_count(root);
	levels = malloc(count * sizeof(int));
	if (!levels)
		return ;
	while (level < count)
	{
		g_level = level++;
		levels[g_level] = 1;
		btree_apply_to_level(root, applyf, 0, levels);
	}
}

// t_btree	*btree_create_node(void *item)
// {
// 	t_btree	*btree;

// 	btree = malloc(sizeof(t_btree));
// 	if (!btree)
// 	 	return (0);
// 	btree->item = item;
// 	btree->left = 0;
// 	btree->right = 0;
// 	return (btree);
// }

// void	btree_insert_data(
// 	t_btree **root,
// 	void *item,
// 	int (*cmpf)(void *, void *)
// )
// {
// 	if (!root)
// 		return ;
// 	else if (!*root)
// 		*root = btree_create_node(item);
// 	else if (cmpf(item, (*root)->item) < 0)
// 		btree_insert_data(&((*root)->left), item, cmpf);
// 	else
// 		btree_insert_data(&((*root)->right), item, cmpf);
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

// void	ft_print(void *item, int current_level, int is_first)
// {
// 	printf("item = %s, level = %d, first = %d\n", 
// 		(char *) item, current_level, is_first);
// }

// int	main(int argc, char **argv)
// {
// 	t_btree	**root;
// 	int 	index;

// 	root = malloc(sizeof(t_btree *));
// 	*root = 0;
// 	index = 1;
// 	while (index < argc)
// 		btree_insert_data(root, argv[index++], ft_cmp);

// 	if (*root)
// 		btree_apply_by_level(*root, ft_print);
// 	return (0);
// }
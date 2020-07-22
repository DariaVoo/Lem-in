#include "lemin.h"

t_path *new_path(int *path, int length_path)
{
	t_path	*node;

	node = (t_path *)malloc(sizeof(t_path));
	if (!node)
		return (NULL);
	if (!(node->ants = (int *)malloc(sizeof(int) * length_path)))
		return (0);
	ft_zero(node->ants, length_path);
	node->path = path;
	node->length = length_path;
	node->prior = 0;
	node->last_ant = -1;
	node->next = NULL;
	return (node);
}
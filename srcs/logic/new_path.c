#include "lemin.h"

t_path *new_path(int *path, int length_path)
{
	t_path	*node;

	node = (t_path *)malloc(sizeof(t_path));
	if (!node)
		return (NULL);
	node->path = path;
	node->length = length_path;
	node->next = NULL;
	return (node);
}
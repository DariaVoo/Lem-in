#include "lemin.h"

void free_paths(t_path **paths)
{
	t_path *current;

	current = *paths;
	while (current)
	{
		*paths = current->next;
		free(current->path);
		free(current->ants);
//		current->path = NULL;
//		current->ants = NULL;
		free(current);
		current = *paths;
	}
	*paths = NULL;
}
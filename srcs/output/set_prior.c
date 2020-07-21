#include "lemin.h"

int get_prior(t_path *paths, t_path *current, int curr_len)
{
	int prior;
	t_path *path;

	prior = 0;
	while (paths != current)
	{
		prior += curr_len - paths->length;
		paths = paths->next;
	}
	return (prior);
}

void set_prior(t_path *paths)
{
	t_path *current;

	current = paths;
	while (current)
	{
		current = paths;
		current->prior = get_prior(paths, current, current->length);
	}
}

#include "lemin.h"

static int	calculate_prior(t_path *paths, t_path *current, int curr_len)
{
	int		prior;

	prior = 0;
	while (paths != current)
	{
		prior += curr_len - paths->length;
		paths = paths->next;
	}
	return (prior);
}

void		set_prior(t_path *paths)
{
	t_path	*current;

	current = paths;
	while (current)
	{
		current->prior = calculate_prior(paths, current, current->length);
		current = current->next;
	}
}

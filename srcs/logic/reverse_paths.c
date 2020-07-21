#include "lemin.h"

void		reverse_paths(t_path **begin_list)
{
	t_path	*current;
	t_path	*previous;
	t_path	*next;

	current = *begin_list;
	previous = 0;
	while (current)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*begin_list = previous;
}
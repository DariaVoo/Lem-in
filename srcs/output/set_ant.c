#include "lemin.h"

int set_ant(t_path *paths, int ant)
{
	int i;
	int finish;

	finish = 0;
	i = paths->last_ant + 1;
	if (i == paths->length - 1) // сейчас кто-то перейдёт на финиш
		finish = 1;
	while (i)
	{
		paths->ants[i] = paths->ants[i - 1];
		if (i != paths->length)
			ft_printf("L%d-%d ", paths->ants[i], paths->path[i]);
		i--;
	}
	paths->ants[i] = ant;
	if (!finish)
		paths->last_ant++;
	ft_printf("L%d-%d ", paths->ants[i], paths->path[i]);
	return (finish);
}
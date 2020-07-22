#include "lemin.h"

int move_ants(t_path *path)
{
	int i;
	int j;
	int finish;

	finish = 0;
	j = path->last_ant;
	i = path->last_ant + 1;
	ft_printf("LAST: %d\t", j);
	if (j == -1 || path->ants[j] == 0)
		return (0);
	if (i == path->length) // сейчас кто-то перейдёт на финиш
		finish = 1;//Не работает
	while (path->ants[j] != 0 && j != -1)
	{
		path->ants[i] = path->ants[j];
		if (i != path->length)
			ft_printf("L%d-%d ", path->ants[i], path->path[i]);
		i--;
		j--;
	}
	path->ants[i] = 0;
	if (!finish)
		path->last_ant++;
	return (finish);
}
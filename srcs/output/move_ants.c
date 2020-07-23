#include "lemin.h"

int move_ants(t_path *path)
{
	int i;
	int j;
	int finish;

	finish = 0;
	j = path->last_ant;
	i = path->last_ant + 1;
	if (j == -1 || path->ants[j] == 0)
		return (0);
	if (i == path->length) // сейчас кто-то перейдёт на финиш
		finish = 1;
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


int move_antsssssss(t_path *path)
{//Это тоже самое, только с одной переменной, но вычисляться из-за этого будет дольше
	int i;
	int finish;

	finish = 0;
	i = path->last_ant;
	if (i == -1 || path->ants[i] == 0)
		return (0);
	if (i + 1 == path->length)
		finish = 1;
	while (i != -1 && path->ants[i] != 0)
	{
		path->ants[i + 1] = path->ants[i];
		if (i != path->length)
			ft_printf("L%d-%d ", path->ants[i + 1], path->path[i + 1]);
		i--;
	}
	path->ants[i + 1] = 0;
	if (!finish)
		path->last_ant++;
	return (finish);
}

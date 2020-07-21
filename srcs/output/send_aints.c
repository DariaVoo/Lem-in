#include "lemin.h"

int get_prior(int i, t_path **paths, int curr_len)
{
	int prior;

	prior = 0;
	while (i)
	{
		prior += curr_len - paths[i]->length;
		i--;
	}
	return (prior);
}

void set_prior(t_path **paths)
{
	int i;
	t_path *current;

	i = 0;
	current = paths[i];
	while (current)
	{
		current = paths[i];
		current->prior = get_prior(i, paths, current->length);
		i++;
	}
}

void send_ants(int **graph, int count_ants, t_path **paths)
{
	t_path *current;
	int i; //текущий путь

	while (count_ants)
	{
		i = 0;
		current = paths[i];
		while (current)
		{
			if (count_ants < current->prior) // если не выгодно пускать пуравья по этому пути
				break ;
			//пускаем муравья по этому пути TODO
			i++;
			current = paths[i];
			count_ants--;
		}
		count_ants--;
	}
}
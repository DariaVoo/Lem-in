#include "lemin.h"

void send_ants(int **graph, int count_ants, t_path **paths)
{
	t_path *current;
	int i; //текущий путь

	set_prior(paths);
	while (count_ants)
	{
		i = 0;
		current = paths[i];
		while (current)
		{
			if (count_ants < current->prior) // если не выгодно пускать муравья по этому пути
				break ;
			//пускаем муравья по этому пути TODO
			current->count_ant++;
			t_ant a;
			a.index_path = 0;
			a.path = current;//TODO new ant

			i++;
			current = paths[i];
			count_ants--;
		}
		count_ants--;
	}
}

int print_ants(int **graph, int count_ants, t_path **paths, t_ant *ants)
{
	int i;
	int finish;

	while (finish != count_ants)
	{
		while (i < )
		i++;
	}
}
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
		ft_printf("L%d-%d ", paths->ants[i], paths->path[i]);
		i--;
	}
	paths->ants[i] = ant;
	paths->last_ant++;
	ft_printf("L%d-%d ", paths->ants[i], paths->path[i]);
	return (finish);
}


void send_ants(int **graph, int count_ants, t_path *paths)
{
	t_path *current;
	int at_finish;
	int ant;

	ant = 1;
	at_finish = 0;
	set_prior(paths); // вычисляем приоритеты
	while (ant < count_ants)
	{
		current = paths;
		while (current)
		{
			if (count_ants - ant < current->prior) // если не выгодно пускать муравья по этому пути
				break ;

			//пускаем муравья по этому пути
			at_finish += set_ant(current, ant);
			current = current->next;
			ant++;
		}
		ft_printf("\n");
	}
	ft_printf("NNNNNNN\n");
	while (at_finish < count_ants)
	{
		current = paths;
		while (current)
		{
			ft_printf("\t\tANTS: ");
			print_path(current->ants, current->length);

			at_finish += move_ants(current);
			current = current->next;
		}
		ft_printf("\n");
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <snorcros@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:36:42 by snorcros          #+#    #+#             */
/*   Updated: 2020/07/26 21:05:20 by snorcros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "lemin.h"

void send_ants(t_room *graph, int count_ants, t_path *paths)
{
	t_path *current;
	int at_finish;
	int ant;

	ant = 1;
	at_finish = 0;
	set_prior(paths); // вычисляем приоритеты
	while (ant < count_ants + 1)
	{
		current = paths;
		while (current)
		{
			if (count_ants - ant < current->prior) // если не выгодно пускать муравья по этому пути
				break ;

			//пускаем муравья по этому пути
			at_finish += set_ant(current, ant, graph);
			current = current->next;
			ant++;
		}
		while (current)
    	{
        	at_finish += move_ants(current, graph);
        	current = current->next;
    	}
		ft_printf("\n");
	}
//	ft_printf("NNNNNNN\n");
	
	while (at_finish < count_ants)
	{
		current = paths;
		while (current)
		{
//			ft_printf("\tANTS: ");
//			print_path(current->ants, current->length);

			at_finish += move_ants(current, graph);
			current = current->next;
		}
		ft_printf("\n");
	}
//	ft_printf("\nAt finish: %d\n", at_finish);
}
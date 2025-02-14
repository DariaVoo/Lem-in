/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:36:42 by snorcros          #+#    #+#             */
/*   Updated: 2020/07/26 21:05:20 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		step_all(t_path *current, t_room *graph, int *move)
{
	int at_finish;

	at_finish = 0;
	while (current)
	{
		at_finish += move_ants(current, graph, move);
		current = current->next;
	}
	return (at_finish);
}

void	print_n(int *move)
{
	if (*move)
		ft_printf("\n");
	*move = 0;
}

void	send_ants(t_room *graph, int count_ants, t_path *paths)
{
	int		ant;
	int		move;
	int		at_finish;
	t_path	*current;

	ant = 1;
	at_finish = 0;
	move = 0;
	while (ant < count_ants + 1 && (current = paths))
	{
		while (current)
		{
			if (count_ants - ant < current->prior)
				break ;
			at_finish += set_ant(current, ant++, graph, &move);
			current = current->next;
		}
		at_finish += step_all(current, graph, &move);
		print_n(&move);
	}
	while (at_finish < count_ants && (current = paths))
	{
		at_finish += step_all(current, graph, &move);
		print_n(&move);
	}
}

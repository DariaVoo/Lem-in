/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ant.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:36:51 by snorcros          #+#    #+#             */
/*   Updated: 2020/07/26 21:05:20 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int set_ant(t_path *paths, int ant, t_room *graph)
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
			ft_printf("L%d-%s ", paths->ants[i], graph[paths->path[i]].name);
		i--;
	}
	paths->ants[i] = ant;
	if (!finish)
		paths->last_ant++;
	ft_printf("L%d-%s ", paths->ants[i], graph[paths->path[i]].name);
	return (finish);
}
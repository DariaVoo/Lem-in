/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:36:07 by snorcros          #+#    #+#             */
/*   Updated: 2020/07/26 21:05:21 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int move_ants(t_path *path, t_room *graph)
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
	{
		i--;
		j--;
		finish = 1;
	}
	while (j != -1 && path->ants[j] != 0)
	{
		path->ants[i] = path->ants[j];
		ft_printf("L%d-%s ", path->ants[i], graph[path->path[i]].name);
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
	i = path->last_ant + 1;
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

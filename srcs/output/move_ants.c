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

int move_ants(t_path *path, t_room *graph, int *move)
{
	int i;
	int j;
	int finish;

	finish = 0;
	j = path->last_ant;
	i = path->last_ant + 1;
	if (j == -1 || path->ants[j] == 0)
		return (0);
	if (i == path->length)
	{
		i--;
		j--;
		finish = 1;
	}
	while (j != -1 && path->ants[j] != 0)
	{
		path->ants[i] = path->ants[j--];
		*move = 1;
		ft_printf("L%d-%s ", path->ants[i], graph[path->path[i]].name);
		i--;
	}
	path->ants[i] = 0;
	if (!finish)
		path->last_ant++;
	return (finish);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:37:25 by snorcros          #+#    #+#             */
/*   Updated: 2020/07/25 12:37:25 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	*set_path(int len, int *stack_path, t_room *graph, int end)
{
	int	i;
	int j;
	int	*path;

	i = 0;
	j = 1;
	if (!(path = (int *)malloc(sizeof(int) * len)))
		return (0);
	while (j < len)
	{
		path[i] = stack_path[j];
		graph[stack_path[j]].num_of_edges = 0;
		i++;
		j++;
	}
	path[i] = end;
	return (path);
}

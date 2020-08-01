/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:37:04 by snorcros          #+#    #+#             */
/*   Updated: 2020/07/26 20:39:40 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	bfs(t_room *graph, size_t count_v, int *distance, int *queue)
{
	int j;
	int v;
	int u;
	int head;
	int end;

	head = 0;
	queue[0] = 0;
	end = 1;
	while (head < count_v)
	{
		u = queue[head++];
		j = 0;
		while (j < graph[u].ed_num)
		{
			v = graph[u].edges[j++];
			if (distance[v] == 0 && v != 0)
			{
				distance[v] = distance[u] + 1;
				queue[end] = v;
				end++;
			}
		}
	}
	return (distance[count_v - 1]);
}

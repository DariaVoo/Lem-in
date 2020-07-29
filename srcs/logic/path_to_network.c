/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <snorcros@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:37:25 by snorcros          #+#    #+#             */
/*   Updated: 2020/07/25 12:37:25 by snorcros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "lemin.h"

int find_index_flow(t_room current, int edg)
{
	int i = 0;
	while (i < current.num_of_edges)
	{
		if (current.edges[i] == edg)
			return i;
		i++;
	}
	return 0;
}

int path_to_network(t_room *graph, int len, int *stack_path)
{
	int i = 0;
	int curr;
	int prev;
	int index;

	prev = 0;
	//i++;
	while (i < len)
	{
		curr = stack_path[i];
		index = find_index_flow(graph[prev], curr);
		graph[prev].flow[index] = 1;
		index = find_index_flow(graph[curr], prev);
		graph[curr].flow[index] = 0;

		graph[prev].out = curr;
		graph[curr].in_path = 1;
		graph[curr].in = prev;
		prev = curr;
		i++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:37:10 by snorcros          #+#    #+#             */
/*   Updated: 2020/07/26 20:45:15 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	find_path(int start, int end, t_room *graph, int *distance, char *visited, int *stack)
{
	int u;
	int i;
	int top;

	i = 0;
	top = 0;
	stack[top] = start;
	while (1)
	{
		while (i < graph[start].num_of_edges)
		{
			u = graph[start].edges[i];
			if ((distance[u] == distance[start] + 1) && (visited[u] == '\0'))
			{
				top++;
				stack[top] = u;
				start = u;
				if (start != end)
					visited[start] = '1';
				i = 0;
			}
			else
				i++;
			if (start == end)
				return (top);
		}
		if (i == graph[start].num_of_edges)
		{
			top--;
			if (top == -1)
				return (0);
			start = stack[top];
			i = 0;
		}
	}
}

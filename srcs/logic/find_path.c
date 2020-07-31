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

int stack_pop(int *i, int *top, int *start, int *stack)
{
	*top -= 1;
	if (*top == -1)
		return (0);
	*start = stack[*top];
	*i = 0;
	return (1);
}

int	find_path(int start, int end, t_room *graph, t_dinic vars)
{
	int u;
	int i;
	int top;

	i = 0;
	top = 0;
	vars.queue_stack[top] = start;
	while (1)
	{
		while (i < graph[start].num_of_edges)
		{
			u = graph[start].edges[i];
			if ((vars.distance[u] == vars.distance[start] + 1) && (vars.visited[u] == '\0'))
			{
				top++;
				vars.queue_stack[top] = u;
				start = u;
				if (start != end)
					vars.visited[start] = '1';
				i = 0;
			}
			else
				i++;
			if (start == end)
				return (top);
		}
		if (i == graph[start].num_of_edges)
			if (!stack_pop(&i, &top, &start, vars.queue_stack))
				return (0);
	}
}

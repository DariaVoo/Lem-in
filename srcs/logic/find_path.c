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

int	check_vertex(int *start, int *top, t_dinic *vars, int u)
{
	if ((vars->distance[u] == vars->distance[*start] + 1)
		&& (vars->visited[u] == '\0'))
	{
		*top += 1;
		vars->queue_stack[*top] = u;
		*start = u;
		if (*start != vars->end)
			vars->visited[*start] = '1';
		vars->i = 0;
	}
	else
		vars->i++;
}

int	stack_pop(int *i, int *top, int *start, int *stack)
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
	int top;

	vars.i = 0;
	top = 0;
	vars.queue_stack[top] = start;
	while (1)
	{
		while (vars.i < graph[start].ed_num)
		{
			u = graph[start].edges[vars.i];
			check_vertex(&start, &top, &vars, u);
			if (start == end)
				return (top);
		}
		if (vars.i == graph[start].ed_num)
			if (!stack_pop(&vars.i, &top, &start, vars.queue_stack))
				return (0);
	}
}

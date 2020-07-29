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

int path_to_network(t_room *graph, int len, int *stack_path)
{
	int i = 0;
	int curr;
	int prev;

	prev = stack_path[0];
	i++;
	while (i < len)
	{
		curr = stack_path[i];
		graph[prev].out = curr;
		graph[curr].in_path = 1;
		graph[curr].in = prev;
		prev = curr;
		i++;
	}
}
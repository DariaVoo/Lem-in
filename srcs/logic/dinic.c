/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:37:07 by snorcros          #+#    #+#             */
/*   Updated: 2020/07/26 20:26:13 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_zero(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
}

int		init_dinic(t_dinic *dinic, int count_v, int end)
{
	dinic->end = end;
	dinic->i = 0;
	if (!(dinic->visited = ft_strnew(count_v)))
		return (0);
	if (!(dinic->distance = (int *)malloc(sizeof(int) * count_v)))
		return (0);
	if (!(dinic->queue_stack = (int *)malloc(sizeof(int) * count_v)))
		return (0);
	ft_zero(dinic->queue_stack, count_v);
	ft_zero(dinic->distance, count_v);
	return (1);
}

int		free_dinic(t_dinic *dinic)
{
	free(dinic->visited);
	free(dinic->distance);
	free(dinic->queue_stack);
	return (1);
}

t_path	*dinic(t_room *graph, int count_v, int end)
{
	t_dinic dinic_var;
	t_path	*paths;
	int		len;

	paths = NULL;
	if (!init_dinic(&dinic_var, count_v, 0))
		return (NULL);
	while (bfs(graph, count_v, dinic_var.distance, dinic_var.queue_stack))
	{
		ft_zero(dinic_var.queue_stack, count_v);
		while ((len = find_path(0, end, graph, dinic_var)))
		{
			add_path(&paths, new_path(
					set_path(len, dinic_var.queue_stack, graph, end), len));
			ft_zero(dinic_var.queue_stack, count_v);
		}
		ft_zero(dinic_var.distance, count_v);
		dinic_var.visited = ft_memset(dinic_var.visited, '\0', count_v);
	}
	reverse_paths(&paths);
	free_dinic(&dinic_var);
	return (paths);
}

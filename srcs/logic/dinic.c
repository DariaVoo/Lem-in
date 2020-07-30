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

void	ft_zero(int *arr, size_t size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
}

int		init_dinic(int **distance, int **queue_stack,
					char **visited, int count_v)
{
	if (!(*visited = ft_strnew(count_v)))
		return (0);
	if (!(*distance = (int *)malloc(sizeof(int) * count_v)))
		return (0);
	if (!(*queue_stack = (int *)malloc(sizeof(int) * count_v)))
		return (0);
	ft_zero(*queue_stack, count_v);
	ft_zero(*distance, count_v);
	return (1);
}

int		free_dinic(int **distance, int **queue_stack, char **visited)
{
	free(*visited);
	free(*distance);
	free(*queue_stack);
}

t_path	*dinic(t_room *graph, int count_v, int end)
{
	int		*distance;
	int		*queue_stack;
	char	*visited;
	t_path	*paths;
	int		len;

	paths = NULL;
	if (!init_dinic(&distance, &queue_stack, &visited, count_v))
		return (NULL);
	while (bfs(graph, count_v, distance, queue_stack))
	{
		ft_zero(queue_stack, count_v);
		while ((len = find_path(0, end, graph, distance, visited, queue_stack)))
		{
			add_path(&paths, new_path(set_path(len, queue_stack, graph, end),
												len));
			ft_zero(queue_stack, count_v);
		}
		ft_zero(distance, count_v);
		visited = ft_memset(visited, '\0', count_v);
	}
	reverse_paths(&paths);
	free_dinic(&distance, &queue_stack, &visited);
	return (paths);
}

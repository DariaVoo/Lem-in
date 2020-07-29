/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <snorcros@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 12:37:25 by snorcros          #+#    #+#             */
/*   Updated: 2020/07/28 12:37:25 by snorcros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "lemin.h"

t_path *full_dinic(t_room *graph, size_t count_v)
{
	int *distance; // расстояния до вершин
	int *queue_stack; // очередь
	int *prev; //
	char *visited; // посещена вершина или нет
	t_path *paths; // блокирующие пути
	int len; // длина найденного блокирующего пути
	int end = (int)count_v - 1;

	paths = NULL;
	if (!(visited = ft_strnew(count_v)))
		return (NULL);
	if (!(distance = (int *)malloc(sizeof(int) * count_v)))
		return (NULL);
	if (!(prev= (int *)malloc(sizeof(int) * count_v)))
		return (NULL);
	if (!(queue_stack = (int *)malloc(sizeof(int) * count_v)))
		return (NULL);
	ft_zero(queue_stack, count_v);
	ft_zero(distance, count_v);
	ft_zero(prev, count_v);

	ft_printf("search...\n");
	/** Добавляем кратчайший путь в paths[0]*/
	while (bfs(graph, count_v, distance, queue_stack)) // достижима ли t из s
	{
		ft_zero(queue_stack, count_v);
		while ((len = find_flow(0, end, graph, distance, visited, queue_stack))) // ищем блокирующие пути
		{
			//строим путь
			path_to_network(graph, len, queue_stack + 1);
			print_arr(queue_stack, len + 1);
			ft_zero(queue_stack, count_v);
		}
		ft_zero(distance, count_v);
		visited = ft_memset(visited, '\0', count_v);
	}
	ft_zero(queue_stack, count_v);
	ft_zero(distance, count_v);
	bfs_get_paths(graph, count_v, distance, queue_stack, prev);
	paths = get_paths(graph, end, prev, distance);
	//reverse_paths(&paths);
	free(prev);
	free(visited);
	free(distance);
	free(queue_stack);
	return (paths);
}



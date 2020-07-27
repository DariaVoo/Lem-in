/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <snorcros@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:37:07 by snorcros          #+#    #+#             */
/*   Updated: 2020/07/26 20:26:13 by snorcros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "lemin.h"

void ft_zero(int *arr, size_t size)
{
	int i = 0;

	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
}

// Возвращает массив из путей
t_path *dinic(t_room *graph, size_t count_v)
{
	int *distance; // расстояния до вершин
	int *queue_stack; // очередь
	char *visited; // посещена вершина или нет
	t_path *paths; // блокирующие пути
	int len; // длина найденного блокирующего пути
	int end = (int)count_v - 1;

	paths = NULL;
	if (!(visited = ft_strnew(count_v)))
		return (NULL);
	if (!(distance = (int *)malloc(sizeof(int) * count_v)))
		return (NULL);
	if (!(queue_stack = (int *)malloc(sizeof(int) * count_v)))
		return (NULL);
//	ft_memset(queue_stack, 0, count_v);
//	ft_memset(distance, 0, count_v);
	ft_zero(queue_stack, count_v);
	ft_zero(distance, count_v);

	/** Добавляем кратчайший путь в paths[0]*/
	while (bfs(graph, count_v, distance, queue_stack)) // достижима ли t из s
	{
		ft_zero(queue_stack, count_v);
		while ((len = find_path(0, end, graph, distance, visited, queue_stack))) // ищем блокирующие пути
		{
			//строим путь
			add_path(&paths, new_path(set_path(len, queue_stack, graph, end), len));
			ft_zero(queue_stack, count_v);
		}
		ft_zero(distance, count_v);
		visited = ft_memset(visited, '\0', count_v);
	}
	reverse_paths(&paths);
	free(visited);
	free(distance);
	free(queue_stack);
	return (paths);
}



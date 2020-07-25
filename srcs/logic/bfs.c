/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <snorcros@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:37:04 by snorcros          #+#    #+#             */
/*   Updated: 2020/07/25 12:37:04 by snorcros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "lemin.h"

int bfs(int **graph, size_t count_v, int *distance, int *queue)
{
	int j; // индекс для второй стороны ребра (u, v)
	int v;
	int u;
	int head, end;

//	ft_printf("\nBFS first distance: %d\n", distance[count_v - 1]);
	head = 0; // индекс начала очереди
	queue[0] = 0; // закидываем в очередь вершину s
	end = 1; // индекс конца очереди
	while (head < count_v)
	{
		u = queue[head]; // запоминаем какую вершину мы будем рассматривать
		head++; // "удаляем" вершину из очереди
		j = 0;
		while ((v = graph[u][j]) != 0) // смотрим все рёбра этой вершины
		{
			if (distance[v] == 0) // расстояние до этой вершины ещё не вычислено
			{
				distance[v] = distance[u] + 1;
				queue[end] = v; // добавляем вершину в очередь
				end++;
			}
			j++;
		}
	}
//	ft_printf("BFS distance: %d\n", distance[count_v - 1]);
	return (distance[count_v - 1]);
}

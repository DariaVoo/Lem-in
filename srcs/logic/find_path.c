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

int find_path(int start, int end, t_room *graph, int *distance, char *visited, int *stack)
{
	int u;
	int i = 0;
	int top = 0; // указатель на вершину стека

	stack[top] = start; // закидываем на стек start = 0
	u = 1;
	while (1)
	{
		while (i < graph[start].num_of_edges) // смотрим все рёбра
		{
			u = graph[start].edges[i];
			if ((distance[u] == distance[start] + 1) && (visited[u] == '\0')) // если смежная вершина в следующем слое(поиск по вспомогательной слоистой сети)
			{
				top++;
				stack[top] = u; // кладём на стек
				start = u;
				if (start != end)
					visited[start] = '1'; // Отмечаем, что посетили эту вершину
				i = 0;
			} else
				i++;

			if (start == end)
				return (top);
		}
		if (i == graph[start].num_of_edges) // все рёбра перебрали, а пути не нашли
		{
			top--; // убираем со стека
			if (top == -1)
				return (0);
			start = stack[top];
			i = 0;
		}
	}
}
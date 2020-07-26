/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <snorcros@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:37:10 by snorcros          #+#    #+#             */
/*   Updated: 2020/07/26 20:45:15 by snorcros         ###   ########lyon.fr   */
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
		//ft_printf("top %d\ti %d\tu %d start %d\n", top, i, u, start);
		while (i < graph[start].num_of_edges) // смотрим все рёбра
		{
			u = graph[start].edges[i];

/*			ft_printf("top %d\ti %d\tu %d start %d dist %d dist start %d\n", top, i, u, start, distance[u], distance[start]);
*//*			sleep(10);
			print_arr(distance, end);
			sleep(10);*/
			if ((distance[u] == distance[start] + 1) && (visited[u] == '\0')) // если смежная вершина в следующем слое(поиск по вспомогательной слоистой сети)
			{
				top++;
				stack[top] = u; // кладём на стек
				start = u;
				//ft_printf("START %d\n", start);
				if (start != end)
					visited[start] = '1'; // Отмечаем, что посетили эту вершину
				i = 0;
			} else
				i++;

			if (start == end)
				return (top);
		}
		//ft_printf("top1 %d name u %s\n", top, graph[u].name);
		if (i == graph[start].num_of_edges) // все рёбра перебрали, а пути не нашли
		{
			top--; // убираем со стека
			//ft_printf("top2 %d\n", top);
			if (top == -1)
				return (0);
			start = stack[top];
			i = 0;
		}
	}
}
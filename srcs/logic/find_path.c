#include "lemin.h"

int find_path(int start, int end, int **graph, int *distance, char *visited, int *stack)
{
	int u;
	int i = 0;
	int top = 0; // указатель на вершину стека

	stack[top] = start; // закидываем на стек start = 0
	while (1)
	{
		while ((u = graph[start][i]) != 0) // смотрим все рёбра
		{
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
		if (!u)
		{
			top--; // убираем со стека
			if (top == -1)
				return (0);
			start = stack[top];
			i = 0;
		}
	}
}
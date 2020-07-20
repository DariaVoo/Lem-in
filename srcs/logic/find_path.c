#include "lemin.h"

int *dfs(size_t start, int *adjacent_v, char *visited, int *prev, size_t count_v) {
	int u;
	int i;

	i = 0;
	visited[start] = '1'; // Отмечаем, что поетили эту вершину
	if (start == count_v)
		return (prev);
	while ((u = adjacent_v[i]) != 0) // пока есть смежные вершины
	{
		if (visited[u] == '\0') {
			prev[u] = start;
			dfs(u, adjacent_v, visited, prev, count_v);
		}
		i++;
	}
	return (prev);// массив предыдущих вершин - перевернутый блокирющий путь
}

int find_path(int start, int end, int **graph, int *distance, char *visited, int *prev)
{
	int u;
	int i = 0;

	if (start == end)
		return (1);

	while ((u = graph[start][i]) != 0)
	{
		if ((distance[u] == distance[start] + 1) && (visited[u] == '\0')) // если смежная вершина в следующем слое(поиск по вспомогательной слоистой сети)
		{
			prev[u] = start;
			if (find_path(u, end, graph, distance, visited, prev))
			{
				visited[start] = '1'; // Отмечаем, что посетили эту вершину
				if (start)
					graph[start][0] = 0;
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int find_pathh(int start, int end, int **graph, int *distance, char *visited, int *stack)
{
	int u;
	int i = 0;
	int top = 0; // указатель на вершину стека

	stack[top] = start; // можно убрать ибо всегда start = 0
	while (top != -1)
	{
		while ((u = graph[start][i]) != 0)
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
	return (0);
}
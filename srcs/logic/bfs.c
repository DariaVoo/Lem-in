#include "lemin.h"

int bfs(int **graph, size_t count_v, int *distance, int *queue)
{
	int j; // индекс для второй стороны ребра (u, v)
	int v;
	int head, end;

	ft_printf("in BFS\n");
	head = 0; // индекс начала очереди
	queue[0] = 0; // закидываем в очередь вершину s
	end = 1; // индекс конца очереди

	while (head < count_v)
	{
		int u = queue[head]; // запоминаем какую вершину мы будем рассматривать
		head++; // "удаляем" вершину из очереди
		j = 0;
		while ((v = graph[u][j]) != 0) // смотрим все рёбра этой вершины
		{
			if (distance[v] == 0) // расстояние до этой вершины ещё не вычислено
			{
				distance[v] = distance[u] + 1;
				queue[end] = v; // добавляем вершиу в очередь
				end++;
			}
			j++;
		}
	}
	free(queue);

	return (distance[count_v]);
}

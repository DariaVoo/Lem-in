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


//ptr-available - указатель на первую неудалённую смежную вершину (неудалённое ребро)
int find_path(int start, int end, int **graph, int *distance, char *visited, int *prev, int flag)
{
	int u;
	int i = 0;

	if (start == end) {
		flag = 1; //КОСТЫЛЬтб
		return (1);
	}

	while ((u = graph[start][i]) != 0)
	{
		if ((distance[u] == distance[start] + 1) && (visited[u] == '\0')) // если смежная вершина в следующем слое(поиск по вспомогательной слоистой сети)
		{
			visited[start] = '1'; // Отмечаем, что посетили эту вершину
			if (start)
				graph[start][0] = 0;

			prev[u] = start;
			find_path(u, end, graph, distance, visited, prev, 0);
			return (1);
		}
		i++;
	}
	return (0);
}
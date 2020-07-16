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


//ptr-available - указатель на первую неудалённю смежную вершину (неудалённое ребро)
int *find_path(int start, int end, int **graph, int *distance, char *visited, int *prev, int *ptr_available) {
	int u;

	if (start == end)
		return (prev);
	while ((u = graph[start][ptr_available[start]]) != 0)
	{
		ptr_available[start]++;
		if (distance[u] != distance[start] + 1) // если смежная вершина не в следующем слое, пропускаем её
			continue ;
		if (visited[u] == '\0')//wtf
		{
			prev[u] = start;
/*			find_path(u, adjacent_v, visited, prev);
			return ;*/
		}
	}
	return (0);
}
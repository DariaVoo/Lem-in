#include "lemin.h"

// Возвращает массив из путей
int *dinic(int **graph, size_t count_v)
{
	int *distance; // расстояния до вершин
	int *queue; // очередь
	char *visited; // посещена вершина или нет
	int **paths; // блокирующие пути
	int i; // счётчик для блокирующих путей
	int *path; // найденный блокирующий путь
	int *prev; // для восстановления блокирующего пути
	int end = count_v - 1;

	if (!(visited = ft_strnew(count_v)))
		return (NULL);
	if (!(distance = (int *)malloc(sizeof(int) * count_v)))
		return (NULL);
	if (!(prev = (int *)malloc(sizeof(int) * count_v)))
		return (NULL);
	if (!(queue = (int *)malloc(sizeof(int) * count_v)))
		return (NULL);
	ft_memset(queue, 0, count_v);
	ft_memset(prev, 0, count_v);
	i = 0;

	/**Добавляем кратчайший путь в paths[0]*/
	bfs(graph, count_v, distance, queue, prev);
	while (bfs(graph, count_v, distance, queue, prev)) // достижима ли t из s
	{
		ft_printf("SEARCH\n");
		// заполняем массив из номер первого неудалённого ребра, идущего из u НУЛЯМИ
		while (!find_path(0, end, graph, distance, visited, prev)) // ищем блокирующие пути
		{
			ft_printf("FIND\n");
			//строим путь по prev
			print_path(recover_path(end, prev));
			ft_memset(prev, 0, count_v);
		}
	}
	bfs(graph, count_v, distance, queue, prev);
/*	free(queue);
	free(prev);*/
	return (recover_path(end, prev));
	//return (paths);
}



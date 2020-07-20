#include "lemin.h"

void ft_zero(int *arr, size_t size){
	int i = 0;

	while (i < size){
		arr[i] = 0;
		i++;
	}
}

// Возвращает массив из путей
int *dinic(int **graph, size_t count_v)
{
	int *distance; // расстояния до вершин
	int *queue; // очередь
	char *visited; // посещена вершина или нет
	int **paths; // блокирующие пути
	int i; // счётчик для блокирующих путей
	int *path; // найденный блокирующий путь
	int end = count_v - 1;


	if (!(visited = ft_strnew(count_v)))
		return (NULL);
	if (!(distance = (int *)malloc(sizeof(int) * count_v)))
		return (NULL);
	if (!(queue = (int *)malloc(sizeof(int) * count_v)))
		return (NULL);
	ft_memset(queue, 0, count_v);

	i = 0;


	int len;
	/**Добавляем кратчайший путь в paths[0]*/
	while (bfs(graph, count_v, distance, queue)) // достижима ли t из s
	{
		ft_printf("SEARCH\n");
		ft_zero(queue, count_v);
		while ((len = find_path(0, end, graph, distance, visited, queue))) // ищем блокирующие пути
		{
			//строим путь
			ft_printf("length path: %d\n", len);
			print_path(set_path(len, queue, graph));
			ft_zero(queue, count_v);

		}

		ft_zero(distance, count_v);
		visited = ft_memset(visited, '\0', count_v);

	}
/*	free(queue);*/
	return (path);
	//return (paths);
}



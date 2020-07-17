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
	while (bfs(graph, count_v, distance, queue, prev)) // достижима ли t из s
	{
		ft_printf("SEARCH\n");
		while (find_path(0, end, graph, distance, visited, prev)) // ищем блокирующие пути
		{
			//строим путь по prev
			print_path(recover_path(end, prev));
			ft_memset(prev, 0, count_v); // !!!!! Не работает !!!!!

/*			ft_printf("zero path:\n");
			print_arr(prev, count_v);*/
		}
		ft_zero(distance, count_v); //почему работает только так?????
		ft_printf("distance:\t");
		print_arr(distance, count_v);
	}
/*	free(queue);
	free(prev);*/
	return (path);
	//return (paths);
}



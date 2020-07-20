#include "lemin.h"

void ft_zero(int *arr, size_t size){
	int i = 0;

	while (i < size){
		arr[i] = 0;
		i++;
	}
}

// Возвращает массив из путей
t_path * dinic(int **graph, size_t count_v)
{
	int *distance; // расстояния до вершин
	int *queue_stack; // очередь
	char *visited; // посещена вершина или нет
	t_path *paths; // блокирующие пути
	int len; // длина найденного блокирующего пути
	int end = count_v - 1;


	if (!(visited = ft_strnew(count_v)))
		return (NULL);
	if (!(distance = (int *)malloc(sizeof(int) * count_v)))
		return (NULL);
	if (!(queue_stack = (int *)malloc(sizeof(int) * count_v)))
		return (NULL);
	ft_memset(queue_stack, 0, count_v);


	/** Добавляем кратчайший путь в paths[0]*/
	while (bfs(graph, count_v, distance, queue_stack)) // достижима ли t из s
	{
		ft_printf("SEARCH\n");
		ft_zero(queue_stack, count_v);
		while ((len = find_path(0, end, graph, distance, visited, queue_stack))) // ищем блокирующие пути
		{
			//строим путь
			ft_printf("length path: %d\n", len);
			add_path(&paths, new_path(set_path(len, queue_stack, graph), len));
			print_path(set_path(len, queue_stack, graph));
			ft_zero(queue_stack, count_v);

		}
		ft_zero(distance, count_v);
		visited = ft_memset(visited, '\0', count_v);
	}
	free(queue_stack);
	return (paths);
}



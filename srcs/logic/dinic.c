#include "lemin.h"

// Возвращает массив из путей
int *dinic(int **graph, size_t count_v)
{
	int *distance; // расстояния до вершин
	int *queue; // очередь
	int **paths; // блокирующие пути
	int i; // счётчик для блокирующих путей
	int *path; // найденный блокирующий путь
	int *prev; // для восстановления блокирующего пути

	if (!(distance = (int *)malloc(sizeof(int) * count_v)))
		return (NULL);
	if (!(prev = (int *)malloc(sizeof(int) * count_v)))
		return (NULL);
	if (!(queue = (int *)malloc(sizeof(int) * count_v)))
		return (NULL);
	ft_memset(queue, 0, count_v);
	i = 0;

/*	while (bfs(graph, count_v, distance, queue, prev)) // достижима ли t из s
	{
		// заполняем массив из номер первого неудалённого ребра, идущего из u НУЛЯМИ
		while (paths[i] = find_path()) // ищем блокирующие пути
		{
			//строим путь по prev
			i++;

		}
	}*/
	bfs(graph, count_v, distance, queue, prev);
/*	free(queue);
	free(prev);*/
	return (recover_path(count_v - 1, prev));
	//return (paths);
}



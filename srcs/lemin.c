#include "lemin.h"

void print_arr(int *arr, size_t size)
{
	size_t i = 0;
	ft_printf("size %d\n", size);
	ft_printf("вершина расстояние\n");
	while (i < size) {
		ft_printf("%d\t%d\n", i, arr[i]);
		i++;
	}
	ft_printf("\n");
}

void print_path(int *arr)
{
	int v;
	size_t i = 0;

	ft_printf("Path:\n");
	while ((v = arr[i]) != -1) {
		ft_printf("%d - ", v);
		i++;
	}
	ft_printf("\n");
}

void print_graph(int **graph, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	ft_printf("Граф с количеством вершин %d\n", size);
	ft_printf("вершина: смежные вершины\n");
	while (i < size) {
		j = 0;
		ft_printf("%d:\t", i);
		while (graph[i][j]){
			ft_printf("%d, ", graph[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

int	main(void)
{
	int **graph;
	size_t count_v = 12;
	int end = 11;

	graph = new_table(count_v, 5);
	/** заполняем массив смежности
	 * вершина: смежные вершины*/
	graph[0][0] = 1; //  из вершины s
	graph[0][1] = 2;
	graph[0][2] = 3;

	graph[1][0] = 4;
	graph[1][1] = 5;
	graph[2][0] = 3;

	graph[2][1] = 6;
	graph[3][0] = 5;

//	graph[2][1] = 5;
//	graph[3][0] = 6;

	graph[4][0] = 8;
	graph[5][0] = 8;
	graph[5][1] = 7;

	graph[6][0] = 5;
	graph[6][1] = 9;
	graph[9][0] = 6;
	graph[9][1] = 10;//

	graph[9][0] = 7;
	graph[7][1] = 5;
	graph[7][2] = 8;
	graph[7][3] = 9;

	graph[8][0] = end; // в t
	graph[7][0] = end;
	graph[10][0] = end;
	//print_graph(graph, count_v);

	t_path *paths = dinic(graph, count_v);
	//print_path(path);

	return (0);
}
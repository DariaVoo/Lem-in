/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <snorcros@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:32:43 by snorcros          #+#    #+#             */
/*   Updated: 2020/07/26 20:56:19 by snorcros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "lemin.h"

void print_arr(int *arr, size_t size)
{
	size_t i = 0;
	ft_printf("size %d\t", size);
	//ft_printf("вершина расстояние\n");
	while (i < size) {
		ft_printf("%d - ", arr[i]);
		i++;
	}
	ft_printf("\n");
}

void print_dist(int *arr, size_t size)
{
	size_t i = 0;
	ft_printf("size %d\n", size);
	ft_printf("вершина расстояние\n");
	while (i < size) {
		ft_printf("%d - %d\n", i, arr[i]);
		i++;
	}
	ft_printf("\n");
}

void print_path(int *arr, int len)
{
	int i = 0;

	//ft_printf("Path:\n");
	while (i < len) {
		ft_printf("%d - ", arr[i]);
		i++;
	}
	ft_printf("\t");
}

void print_paths(t_path *paths)
{
	int i = 1;

	ft_printf("PATHS:\n");
	while (paths) {
		ft_printf("\npath%d:\t", i);
		ft_printf("len %d\t", paths->length);
		//ft_printf("\tprior %d\t", paths->prior);
		print_path(paths->path, paths->length);
		paths = paths->next;
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

void print_ed(t_room *graph, int count_v)
{
	int i = 0;
	int j = 0;
	t_room v;

	while (i < count_v)
	{
		v = graph[i];
		j = 0;
		while (j < graph[i].num_of_edges)
		{
			if (graph[i].flow[j] == 1)
				ft_printf("%d-%d ", i, graph[i].edges[j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

int	main(void)
{
	t_path *paths;
	t_lemin lemin;
	int i;
	char    **split_file;

	/** Парсинг*/
	split_file = NULL;
	i = 0;
	init_lemin(&lemin);
	split_file = parser_file(split_file); // считали и засплитили файл

	ft_printf("yes parser file\n");


	// этап валидации. проверяем файл на соответствие нужному
	file_checker(split_file, &lemin);
	ft_printf("yes file cheker\n");


	// Создаем комнаты
	t_room rooms[lemin.room_num];
	while (i < lemin.room_num)
	{
		init_rooms(&rooms[i]);
		i++;
	}
	create_rooms(lemin.room_num, rooms, &lemin, split_file);
	ft_printf("yes create rooms\n");


	// Парсим ребра в массив
	int     edges[lemin.edges_num * 2];
	create_edges_arr(lemin.edges_num * 2, edges, &lemin, split_file, rooms);
	ft_printf("yes create edges arr\n");

	if (!(malloc_rooms_edges(rooms, lemin.room_num)))
	{
		ft_printf("ERROR!\n");
		exit (1);
	}
	init_rooms_edges(rooms, lemin.edges_num * 2, edges, &lemin);
	ft_printf("yes init rooms\n");

 	/** Логика*/
 	if (lemin.ant_num > 100)
		paths = full_dinic(rooms, lemin.room_num);
	else
		paths = dinic(rooms, lemin.room_num);
	//print_ed(rooms, lemin.room_num);
	print_paths(paths);

	if (!paths)
		ft_printf("No Path!\n");
	else
		send_ants(rooms, lemin.ant_num, paths);

	/** Free*/
	i = 0;
	while (i < lemin.room_num)
	{
		free(rooms[i].name);
		free(rooms[i].edges);
		i++;
	}
	ft_free((void**)split_file, lemin.lines_count);
	free_paths(&paths);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:32:43 by snorcros          #+#    #+#             */
/*   Updated: 2020/08/01 17:51:30 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		ft_printf("\tlen %d\t", paths->length);
		//print_path(paths->path, paths->length);
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

int	main(void)
{
	int **graph;
	// size_t count_v = 12;
	// int end = 11;
	// int count_ants = 10;
	// int count_edges = 5;
	t_path *paths;


	t_lemin lemin;
	int i;
	char    **spl_f;

	/** Парсинг*/
	spl_f = NULL;
	i = 0;
	init_lemin(&lemin);
	spl_f = parser_file(spl_f); // считали и засплитили файл

	// этап валидации. проверяем файл на соответствие нужному
	file_checker(spl_f, &lemin);

	// Создаем комнаты
	t_room rooms[lemin.room_num];
	while (i < lemin.room_num)
	{
		init_rooms(&rooms[i]);
		i++;
	}
	create_rooms(lemin.room_num, rooms, &lemin, spl_f);
	chck_rooms(lemin.room_num, rooms);

	// Парсим ребра в массив
	int     edges[lemin.edges_num * 2];
	create_edges_arr(edges, &lemin, spl_f, rooms);
	if (!(malloc_rooms_edges(rooms, lemin.room_num)))
	{
		ft_printf("ERROR!\n");
		exit (1);
	}
	init_rooms_edges(rooms, lemin.edges_num * 2, edges, &lemin);
	chck_edges(lemin.room_num, rooms);

 	/** Логика*/
	paths = dinic(rooms, lemin.room_num);
	//print_paths(paths);
	if (!paths)
		ft_printf("No Path!\n");
	else
		send_ants(rooms, lemin.ant_num, paths);

	/** Free*/
	ft_free_lemin(rooms, spl_f, lemin.room_num, lemin.lines_count, &paths);

	//free_paths(&paths);
	return (0);
}
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

t_room *parse_lemin(t_lemin *lemin, t_room *rooms)
{
	int i;
	char    **spl_f;

	//** Парсинг*//*
	i = 0;
	spl_f = NULL;
	init_lemin(lemin);
	spl_f = parser_file(spl_f); // считали и засплитили файл
	// этап валидации. проверяем файл на соответствие нужному
	file_checker(spl_f, lemin);

	// Создаем комнаты
	if (!(rooms = (t_room *)malloc(sizeof(t_room) * lemin->room_num)))
		return (NULL);
	while (i < lemin->room_num)
	{
		init_rooms(&rooms[i]);
		i++;
	}
	create_rooms(lemin->room_num, rooms, lemin, spl_f);
	chck_rooms(lemin->room_num, rooms);

	// Парсим ребра в массив - в отдельную
	int     edges[lemin->edges_num * 2];

	create_edges_arr(edges, lemin, spl_f, rooms);
	if (!(malloc_rooms_edges(rooms, lemin->room_num)))
	{
		ft_printf("ERROR!\n");
		exit (1);
	}
	init_rooms_edges(rooms, lemin->edges_num * 2, edges, lemin);
	chck_edges(lemin->room_num, rooms);

	ft_free((void**)spl_f, lemin->lines_count);
	return (rooms);
}

int	main(void)
{
	t_path *paths;
	t_lemin lemin;
	t_room *rooms;

	rooms = parse_lemin(&lemin, rooms);
	paths = dinic(rooms, lemin.room_num, lemin.room_num - 1);
	if (!paths)
		ft_printf("No Path!\n");
	else
	{
		set_prior(paths);
		send_ants(rooms, lemin.ant_num, paths);
	}
	ft_free_lemin(rooms, lemin.room_num, &paths);
	return (0);
}
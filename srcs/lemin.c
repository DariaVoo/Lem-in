/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:32:43 by snorcros          #+#    #+#             */
/*   Updated: 2020/08/02 02:43:52 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room *make_rooms(t_room *rooms, t_lemin *lemin)
{
	int		i;
	
	i = 0;
	if (!(rooms = (t_room *)malloc(sizeof(t_room) * lemin->room_num)))
		ft_exit("incorrect MALLOC");
	while (i < lemin->room_num)
	{
		init_rooms(&rooms[i]);
		i++;
	}
	return (rooms);
}

int	main(int ac, char **av)
{
	t_path *paths;
	t_lemin lemin;
	t_room *rooms;

	if (ac != 1)
	{
		ft_printf("Usage: ./lem-in < path_to_map\n");
		return (0);
	}
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:32:43 by snorcros          #+#    #+#             */
/*   Updated: 2020/08/02 20:09:21 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int ac, char **av)
{
	t_path	*paths;
	t_lemin	lemin;
	t_room	*rooms;

	rooms = NULL;
	if (ac != 1 && *av)
	{
		ft_printf("Usage: ./lem-in < path_to_map\n");
		return (0);
	}
	rooms = parse_lemin(&lemin, rooms);
	paths = dinic(rooms, lemin.room_num, lemin.room_num - 1);
	if (!paths)
		ft_exit("No Path!");
	else
	{
		set_prior(paths);
		send_ants(rooms, lemin.ant_num, paths);
	}
	ft_free_lemin(rooms, lemin.room_num, &paths);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:39:33 by erodd             #+#    #+#             */
/*   Updated: 2020/08/01 17:59:42 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	create_rooms(int room_num, t_room *rooms, t_lemin *lemin, char **spl_f)
{
	int		i;
	int		room_id;

	i = 1;
	room_id = 1;
	while (i < lemin->lines_count)
	{
		if (ft_wc(spl_f[i], ' ') == 3)
		{
			if (i == lemin->start_num)
				rooms[0] = create_single_room(0, spl_f[i], &rooms[0]);
			else if (i == lemin->end_num)
				rooms[room_num - 1] =\
				create_single_room(lemin->room_num - 1, spl_f[i], \
				&rooms[lemin->room_num - 1]);
			else
			{
				rooms[room_id] =\
				create_single_room(room_id, spl_f[i], &rooms[room_id]);
				room_id++;
			}
		}
		i++;
	}
}

t_room	create_single_room(int id, char *line, t_room *room)
{
	char	**lines;
	int		i;

	i = 0;
	lines = ft_strsplit(line, ' ');
	room->id = id;
	room->name = ft_strdup(lines[0]);
	while (ft_isdigit(lines[1][i]) || lines[1][i] == '-')
		i++;
	if (lines[1][i])
		ft_exit("Incorrect coordinates\n");
	i = 0;
	while (ft_isdigit(lines[2][i]) || lines[2][i] == '-')
		i++;
	if (lines[2][i])
		ft_exit("Incorrect coordinates\n");
	room->x = ft_atoi(lines[1]);
	room->y = ft_atoi(lines[2]);
	ft_free((void**)lines, 3);
	return (*room);
}

void	create_edges_arr(int *edges, t_lemin *lemin, char **spl_f, t_room *rms)
{
	int		i;
	int		k;
	char	**lines;

	i = lemin->room_num;
	k = 0;
	while (i < lemin->lines_count)
	{
		lines = ft_strsplit(spl_f[i], '-');
		if (ft_wc(spl_f[i], '-') == 2)
		{
			count_room_edges(k, edges, rms, lemin, lines);
			k += 2;
		}
		ft_free((void**)lines, 2);
		i++;
	}
}

int		add_edge(t_room *rooms, int id_find)
{
	rooms[id_find].ed_num++;
	return (rooms[id_find].id);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:49:41 by erodd             #+#    #+#             */
/*   Updated: 2020/08/02 17:09:32 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		correct_room(char *str, t_lemin *lemin)
{
	char	**lines;
	int		i;

	lines = ft_strsplit(str, ' ');
	i = 0;
	if (str[0] == 'L')
		ft_exit("incorrect ROOM name");
	while (ft_isdigit(lines[1][i]) || lines[1][i] == '-')
		i++;
	if (lines[1][i])
		ft_exit("Incorrect coordinates");
	i = 0;
	while (ft_isdigit(lines[2][i]) || lines[2][i] == '-')
		i++;
	if (lines[2][i])
		ft_exit("Incorrect coordinates");
	lemin->room_num++;
	return (1);
}

void	chck_rooms(int room_num, t_room *rooms)
{
	int		i;
	int		j;

	i = 0;
	while (i < room_num)
	{
		j = i + 1;
		while (j < room_num)
		{
			if (ft_strcmp(rooms[i].name, rooms[j].name) == 0)
				ft_exit("same ROOM name");
			j++;
		}
		i++;
	}
}

void	start_end_count(char **spl_f, t_lemin *lemin)
{
	int		i;
	int		start_count;
	int		end_count;

	i = 1;
	start_count = 0;
	end_count = 0;
	while (i < lemin->lines_count)
	{
		if (ft_strcmp(spl_f[i], "##start\0") == 0 &&
				ft_wc(spl_f[i + 1], ' ') == 3)
			start_count = ft_start(lemin, start_count, i);
		if (ft_strcmp(spl_f[i], "##end\0") == 0 &&
				ft_wc(spl_f[i + 1], ' ') == 3)
			end_count = ft_end(lemin, end_count, i);
		i++;
	}
	start_end_fail(start_count, end_count);
}

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

	lines = ft_strsplit(line, ' ');
	room->id = id;
	room->name = ft_strdup(lines[0]);
	room->x = ft_atoi(lines[1]);
	room->y = ft_atoi(lines[2]);
	ft_free((void**)lines, 3);
	return (*room);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:47:05 by erodd             #+#    #+#             */
/*   Updated: 2020/08/02 17:24:19 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_start(t_lemin *lemin, int start_count, int i)
{
	lemin->start_num = i + 1;
	return (start_count + 1);
}

int		ft_end(t_lemin *lemin, int end_count, int i)
{
	lemin->end_num = i + 1;
	return (end_count + 1);
}

void	start_end_fail(int start_count, int end_count)
{
	if (start_count > 1 || start_count == 0)
		ft_exit("Incorrect START count");
	if (end_count > 1 || end_count == 0)
		ft_exit("Incorrect END count");
}

t_room	*make_rooms(t_room *rooms, t_lemin *lemin)
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

int		malloc_rooms_edges(t_room *rooms, int count_rooms)
{
	int		i;

	i = 0;
	while (i < count_rooms)
	{
		if (!(rooms[i].edges = (int *)malloc(sizeof(int) * rooms[i].ed_num)))
			return (0);
		i++;
	}
	return (1);
}

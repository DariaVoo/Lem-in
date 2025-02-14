/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:40:13 by erodd             #+#    #+#             */
/*   Updated: 2020/08/02 16:45:53 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	init_lemin(t_lemin *lemin)
{
	lemin->ant_num = 0;
	lemin->edges_num = 0;
	lemin->end_num = 0;
	lemin->room_num = 0;
	lemin->start_num = 0;
	lemin->lines_count = 1;
}

void	init_rooms(t_room *room)
{
	room->id = 0;
	room->name = NULL;
	room->x = 0;
	room->y = 0;
	room->ed_num = 0;
	room->index_edge = 0;
	room->edges = NULL;
}

void	str_init(char **str, char **str2, char **str3)
{
	*str = NULL;
	*str2 = NULL;
	*str3 = NULL;
}

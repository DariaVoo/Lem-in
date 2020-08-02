/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edges.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:49:37 by erodd             #+#    #+#             */
/*   Updated: 2020/08/02 17:50:41 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	create_edges_arr(int *edges, t_lemin *lemin, char **spl_f, t_room *rms)
{
	int		i;
	int		k;
	char	**lines;
	t_count count;

	i = lemin->room_num;
	k = 0;
	while (i < lemin->lines_count)
	{
		lines = ft_strsplit(spl_f[i], '-');
		if (ft_wc(spl_f[i], '-') == 2)
		{
			count.k = k;
			count.lines = lines;
			count_room_edges(count, edges, rms, lemin);
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

void	init_rooms_edges(t_room *rooms, int l_edges, int *edges)
{
	int		i;
	int		j;

	i = 0;
	j = i + 1;
	while (i < l_edges && j < l_edges)
	{
		rooms[edges[j]].edges[rooms[edges[j]].index_edge] = edges[i];
		rooms[edges[j]].index_edge++;
		rooms[edges[i]].edges[rooms[edges[i]].index_edge] = edges[j];
		rooms[edges[i]].index_edge++;
		i += 2;
		j = i + 1;
	}
}

void	chck_edges(int room_num, t_room *rooms)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < room_num)
	{
		j = 0;
		while (j < rooms[i].ed_num)
		{
			k = j + 1;
			while (k < rooms[i].ed_num && j < rooms[i].ed_num - 1)
			{
				if (rooms[i].edges[j] == rooms[i].edges[k])
					ft_exit("Same links");
				k++;
			}
			j++;
		}
		i++;
	}
}

void	count_room_edges(t_count cnt, int *edges, t_room *rooms, t_lemin *lmn)
{
	int		id_find;
	int		find_1;
	int		find_2;

	id_find = 0;
	find_1 = 0;
	find_2 = 0;
	while (id_find < lmn->room_num)
	{
		if (find_1 == 0 && ft_strcmp(rooms[id_find].name, cnt.lines[0]) == 0)
		{
			edges[cnt.k] = add_edge(rooms, id_find);
			cnt.k++;
			find_1 = 1;
		}
		if (find_2 == 0 && ft_strcmp(rooms[id_find].name, cnt.lines[1]) == 0)
		{
			edges[cnt.k] = add_edge(rooms, id_find);
			cnt.k++;
			find_2 = 1;
		}
		id_find++;
	}
	chk_edge_name(find_1, find_2);
}

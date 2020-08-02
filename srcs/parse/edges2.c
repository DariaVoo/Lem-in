/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edges2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:32:22 by erodd             #+#    #+#             */
/*   Updated: 2020/08/02 17:09:07 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	chk_edge_name(int find_1, int find_2)
{
	if (find_1 == 0 || find_2 == 0)
		ft_exit("Incorrect EDGE name");
}

int		correct_edge(char *str, t_lemin *lemin)
{
	char **lines;

	lemin->edges_num++;
	lines = ft_strsplit(str, '-');
	if (lines[0] == lines[1])
	{
		ft_strdel(lines);
		ft_exit("ROOM links theirselves");
	}
	ft_free((void **)lines, 2);
	return (1);
}

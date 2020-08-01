/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:39:54 by erodd             #+#    #+#             */
/*   Updated: 2020/08/01 17:55:01 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ant_count(char *line)
{
	int	ant_count;
	int	i;

	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	if (line[i])
		ft_exit("Incorrect number of ANTS\n");
	ant_count = ft_atoi(line);
	if (ant_count < 1 || ant_count > INT32_MAX)
		ft_exit("Incorrect number of ANTS\n");
	ft_printf("%d\n", ant_count);
	return (ant_count);
}

void	count_items(char **spl_f, int lines_count, t_lemin *lemin)
{
	int	i;
	int	start_count;
	int	end_count;

	i = 1;
	start_count = 0;
	end_count = 0;
	while (i < lines_count)
	{
		if (ft_wc(spl_f[i], ' ') == 3)
			lemin->room_num++;
		if (ft_strcmp(spl_f[i], "##start\0") == 0 &&
				ft_wc(spl_f[i + 1], ' ') == 3)
			start_count = ft_start(lemin, start_count, i);
		if (ft_strcmp(spl_f[i], "##end\0") == 0 &&
				ft_wc(spl_f[i + 1], ' ') == 3)
			end_count = ft_end(lemin, end_count, i);
		if (ft_wc(spl_f[i], '-') == 2 && ft_wc(spl_f[i], ' ') != 3)
			lemin->edges_num++;
		ft_printf("%s\n", spl_f[i]);
		i++;
	}
	ft_printf("\n");
	start_end_fail(start_count, end_count);
}

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

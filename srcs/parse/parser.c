/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:40:07 by erodd             #+#    #+#             */
/*   Updated: 2020/08/02 20:16:53 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		correct_line(char *str, t_lemin *lemin)
{
	if (ft_wc(str, ' ') == 3)
		return (correct_room(str, lemin));
	else if (ft_strcmp(str, "##start\0") == 0 ||\
	ft_strcmp(str, "##end\0") == 0)
		return (1);
	else if (ft_wc(str, '-') == 2 && ft_wc(str, ' ') != 3)
		return (correct_edge(str, lemin));
	else if (ft_strchr(str, '#'))
		return (1);
	else
		return (0);
}

char	**parser_file(char **spl, t_lemin *lemin)
{
	char	*str;
	char	*str2;
	char	*tmp;

	str_init(&str, &str2, &tmp);
	if (get_next_line_q(0, &tmp))
		lemin->ant_num = ant_count(tmp);
	str = ft_strjoin(tmp, "\n");
	free(tmp);
	while (get_next_line_q(0, &tmp))
	{
		if (correct_line(tmp, lemin))
			str2 = ft_strjoin_n(str, tmp);
		else
			ft_exit("Incorrect MAP");
		lemin->lines_count++;
		free(str);
		str = str2;
		ft_strdel(&tmp);
	}
	if (ft_strstr(str2, "\n\n") != 0 || (spl = ft_strsplit(str2, '\n')) == NULL)
		ft_exit("Wrong MAP");
	str = NULL;
	ft_strdel(&str2);
	return (spl);
}

void	print_input(char **spl_f, t_lemin *lemin)
{
	int		i;

	i = 0;
	while (i < lemin->lines_count)
	{
		ft_putstr(spl_f[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

t_room	*parse_lemin(t_lemin *lemin, t_room *rooms)
{
	char	**spl_f;
	int		*edges;

	spl_f = NULL;
	init_lemin(lemin);
	spl_f = parser_file(spl_f, lemin);
	start_end_count(spl_f, lemin);
	rooms = make_rooms(rooms, lemin);
	create_rooms(lemin->room_num, rooms, lemin, spl_f);
	chck_rooms(lemin->room_num, rooms);
	if (!(edges = (int *)malloc(sizeof(int) * lemin->edges_num * 2)))
		ft_exit("incorrect MALLOC");
	create_edges_arr(edges, lemin, spl_f, rooms);
	if (!(malloc_rooms_edges(rooms, lemin->room_num)))
		ft_exit("incorrect MALLOC");
	init_rooms_edges(rooms, lemin->edges_num * 2, edges);
	chck_edges(lemin->room_num, rooms);
	print_input(spl_f, lemin);
	free(edges);
	ft_free((void**)spl_f, lemin->lines_count);
	return (rooms);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:52:19 by erodd             #+#    #+#             */
/*   Updated: 2020/08/02 16:55:17 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	**ft_free(void **mas, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(mas[i]);
		mas[i] = NULL;
		i++;
	}
	free(mas);
	mas = NULL;
	return (mas);
}

void	ft_free_lemin(t_room *rooms, int r_num, t_path **paths)
{
	int		i;

	i = 0;
	while (i < r_num)
	{
		free(rooms[i].name);
		free(rooms[i].edges);
		i++;
	}
	free_paths(paths);
	free(rooms);
}

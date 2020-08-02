/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:47:05 by erodd             #+#    #+#             */
/*   Updated: 2020/08/02 16:55:40 by erodd            ###   ########.fr       */
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

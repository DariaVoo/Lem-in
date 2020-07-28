/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_prior.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <snorcros@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:36:55 by snorcros          #+#    #+#             */
/*   Updated: 2020/07/25 12:36:55 by snorcros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "lemin.h"

static int	calculate_prior(t_path *paths, t_path *current, int curr_len, int count_ant)
{
	int	prior;
	int len_prev;
	int count_prev;

	prior = 0;
	len_prev = 0;
	count_prev = 0;
	while (paths != current)
	{
		count_prev++;
		len_prev += paths->length;
		prior += curr_len - paths->length;
		paths = paths->next;
	}
	//prior = len_prev + curr_len;
	return (prior);
}

void set_prior(t_path *paths, int count_ant)
{
	t_path	*current;

	current = paths;
	while (current)
	{
		current->prior = calculate_prior(paths, current, current->length, count_ant);
		current = current->next;
	}
}

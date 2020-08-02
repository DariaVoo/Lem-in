/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 15:49:44 by erodd             #+#    #+#             */
/*   Updated: 2020/08/02 16:20:07 by erodd            ###   ########.fr       */
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
		ft_exit("Incorrect input of ANTS");
	ant_count = ft_atoi(line);
	if (ant_count < 1 || ant_count > INT32_MAX)
		ft_exit("Incorrect number of ANTS");
	return (ant_count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <snorcros@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:37:21 by snorcros          #+#    #+#             */
/*   Updated: 2020/07/25 12:37:21 by snorcros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "lemin.h"

t_path *new_path(int *path, int length_path)
{
	t_path	*node;
	ft_printf("LENGTH: %d\n", length_path);

	node = (t_path *)malloc(sizeof(t_path) + sizeof(int) * length_path);
	//node = NULL;
	if (!node)
		return (NULL);
	// if (!(node->ants = (int *)malloc(sizeof(int) * length_path )))
	// 	return (NULL);
	ft_zero(node->ants, length_path);
	node->path = path;
	node->length = length_path;
	node->prior = 0;
	node->last_ant = -1;
	node->next = NULL;
	return (node);
}

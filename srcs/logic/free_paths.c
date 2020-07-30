/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:37:18 by snorcros          #+#    #+#             */
/*   Updated: 2020/07/25 12:37:18 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void free_paths(t_path **paths)
{
	t_path *current;

	current = *paths;
	while (current)
	{
		*paths = current->next;
		free(current->path);
		free(current->ants);
		current->path = NULL;
		current->ants = NULL;
		free(current);
		current = *paths;
	}
	*paths = NULL;
}
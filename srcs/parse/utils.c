/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:39:50 by erodd             #+#    #+#             */
/*   Updated: 2020/08/01 16:39:51 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// word_counter
int	ft_wc(char const *s, char c)
{
	int	q;

	q = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			q++;
		s++;
	}
	return (q);
}

void str_init(char **str, char **str2)
{
	*str = NULL;
	*str2 = NULL;
}

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

void ft_exit(char *str)
{
	ft_putstr(str);
	exit (EXIT_FAILURE);
}

void ft_free_lemin(t_room *rooms, char **split, int r_num, int l_num, t_path **paths)
{
	int i;

	i = 0;
	while (i < r_num)
	{
		free(rooms[i].name);
		free(rooms[i].edges);
		i++;
	}
	ft_free((void**)split, l_num);
	free_paths(paths);
}

void start_end_fail(int start_count, int end_count)
{
	if (start_count > 1 || start_count == 0)
		ft_exit("Incorrect START count\n");
	if (end_count > 1 || end_count == 0)
		ft_exit("Incorrect END count\n");
}

int malloc_rooms_edges(t_room *rooms, int count_rooms)
{
    int i;

    i = 0;
    while (i < count_rooms)
    {
        if (!(rooms[i].edges = (int *)malloc(sizeof(int) * rooms[i].ed_num)))
            return (0);
        i++;
    }
    return (1);
}
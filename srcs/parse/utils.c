/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:39:50 by erodd             #+#    #+#             */
/*   Updated: 2020/08/02 17:23:28 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_wc(char const *s, char c)
{
	int		q;

	q = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			q++;
		s++;
	}
	return (q);
}

void	ft_exit(char *str)
{
	ft_printf("%s\nERROR\n", str);
	exit(EXIT_FAILURE);
}

char	*ft_strjoin_n(char const *s1, char const *s2)
{
	char		*dest;
	size_t		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!dest)
		return (NULL);
	while (*s1)
	{
		dest[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		dest[i] = *s2;
		i++;
		s2++;
	}
	dest[i] = '\n';
	dest[i + 1] = '\0';
	return (dest);
}

int		put_new_line(char **vault, char **line, int fd, int bytes)
{
	int			i;
	char		*tmp;

	i = 0;
	while (vault[fd][i] != '\n' && vault[fd][i] != '\0')
		i++;
	*line = ft_strsub(vault[fd], 0, i);
	if (vault[fd][i] == '\0')
	{
		if (bytes == BUFF_SIZE)
			return (0);
		ft_strdel(&vault[fd]);
	}
	else if (vault[fd][i] == '\n')
	{
		tmp = ft_strsub(vault[fd], i + 1, ft_strlen(vault[fd]) - i);
		ft_strdel(&vault[fd]);
		vault[fd] = tmp;
	}
	return (1);
}

int		get_next_line_q(const int fd, char **line)
{
	char		buffer[BUFF_SIZE + 1];
	static char	*vault[10240];
	char		*tmp;
	int			bytes;

	if (fd < 0 || fd > 10240 || line == NULL)
		return (-1);
	while ((bytes = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[bytes] = '\0';
		if (vault[fd] == NULL)
			vault[fd] = ft_strnew(0);
		tmp = ft_strjoin(vault[fd], buffer);
		ft_strdel(&vault[fd]);
		vault[fd] = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (bytes < 0)
		return (-1);
	else if ((bytes == 0 && vault[fd] == NULL) || \
	(bytes == 0 && vault[fd][0] == '\0'))
		return (0);
	else
		return (put_new_line(vault, line, fd, bytes));
}

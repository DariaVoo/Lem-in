#include "lemin.h"

int *recover_path(size_t end, int *prev)
{
	int		i;
	int		*path;
	int		current;

	i = 0;
	current = (int)end;
	if (!(path = (int *)malloc(sizeof(int) * (int)(end)))) // непонятно сколько памяти выделять
		return (0);
	while (current)
	{
		path[i] = current;
		current = prev[current];
		i++;
	}
	path[i] = 0;
	i++;
	path[i] = -1;
	//ft_printf("in recover\n");
	return (path);
}

int *set_path(int len, int *stack_path, int **graph)
{
	int		i;
	int		*path;

	i = 1;
	if (!(path = (int *)malloc(sizeof(int) * len)))
		return (0);
	path[0] = 0;
	while (i < len)
	{
		path[i] = stack_path[i];
		graph[stack_path[i]][0] = 0;
		i++;
	}
	path[i] = -1;
	return (path);
}


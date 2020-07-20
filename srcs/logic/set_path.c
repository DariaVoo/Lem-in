#include "lemin.h"

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


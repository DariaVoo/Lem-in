#include "lemin.h"

int *set_path(int len, int *stack_path, int **graph, int end)
{
	int	i;
	int j;
	int	*path;

	i = 0;
	j = 1;
	if (!(path = (int *)malloc(sizeof(int) * len)))
		return (0);
	while (j < len)
	{
		path[i] = stack_path[j];
		graph[stack_path[j]][0] = 0;
		i++;
		j++;
	}
	path[i] = end;
	return (path);
}


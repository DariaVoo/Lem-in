#include "lemin.h"

int *recover_path(size_t end, int *prev)
{
	int		i;
	int		*path;
	int		current;

	i = 0;
	current = (int)end;
	if (!(path = (int *)malloc(sizeof(int) * end))) // непонятно сколько памяти выделять
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
	ft_printf("in recover\n");
	return (path);
}



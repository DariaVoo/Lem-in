#ifndef LEMIN_H
# define LEMIN_H

# include <unistd.h>
# include <stdlib.h>
# include "libftprintf.h"

/*typedef struct		s_que
{
	int				vertex;
	struct s_que	*next;
	struct s_que	*prev;
}					t_que;*/

int *bfs(int **graph, size_t count_v);
void print_arr(int *arr, size_t size);

#endif

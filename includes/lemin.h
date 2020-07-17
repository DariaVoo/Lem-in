#ifndef LEMIN_H
# define LEMIN_H

# include <unistd.h>
# include <stdlib.h>
# include "libftprintf.h"

typedef struct		s_path
{
	int	length;
	int	*path;
	struct s_path *next;
}					t_path;


void print_graph(int **graph, size_t size);
int find_path(int start, int end, int **graph, int *distance, char *visited, int *prev);
void print_path(int *arr);
int *recover_path(size_t end, int *prev);
int bfs(int **graph, size_t count_v, int *distance, int *queue, int *prev);
int *dinic(int **graph, size_t count_v);
void print_arr(int *arr, size_t size);

#endif

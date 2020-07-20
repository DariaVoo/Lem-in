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

void	add_path(t_path **alst, t_path *neww);
t_path *new_path(int *path, int length_path);

int *set_path(int len, int *stack_path, int **graph);

t_path * dinic(int **graph, size_t count_v);
int bfs(int **graph, size_t count_v, int *distance, int *queue);
int find_path(int start, int end, int **graph, int *distance, char *visited, int *stack);

void print_path(int *arr);
void print_arr(int *arr, size_t size);
void print_graph(int **graph, size_t size);

#endif

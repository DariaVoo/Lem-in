#ifndef LEMIN_H
# define LEMIN_H

# include <unistd.h>
# include <stdlib.h>
# include "libftprintf.h"

typedef struct		s_path
{
	int	*path;
	int	length;
	int prior;
	int *ants; // муравьи перемещающиеся по пути
	int last_ant; // индекс последнего муравья на этом пути
	struct s_path *next;
}					t_path;

void ft_zero(int *arr, size_t size);

void send_ants(int **graph, int count_ants, t_path *paths);
int move_ants(t_path *path);


void	add_path(t_path **alst, t_path *neww);
t_path *new_path(int *path, int length_path);
void		reverse_paths(t_path **begin_list);
void set_prior(t_path *paths);

int *set_path(int len, int *stack_path, int **graph, int end);

t_path * dinic(int **graph, size_t count_v);
int bfs(int **graph, size_t count_v, int *distance, int *queue);
int find_path(int start, int end, int **graph, int *distance, char *visited, int *stack);

void print_path(int *arr, int len);
void print_arr(int *arr, size_t size);
void print_graph(int **graph, size_t size);

#endif

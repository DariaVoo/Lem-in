#ifndef LEMIN_H
# define LEMIN_H

# include <unistd.h>
# include <stdlib.h>
# include "libftprintf.h"

# define FILE_READ_SIZE 8192

typedef struct		s_lemin
{
	int	ant_num;
	int	room_num;
	int	edges_num;
	int	start_num;
	int	end_num;
	int	lines_count;
}					t_lemin;

typedef struct	s_room
{
	int		id;
	char	*name;
	int		x;
	int		y;
	int		num_of_edges;
	int		index_edge;
	int		*edges;
}				t_room;

/*
** Init functions
*/

void	init_lemin(t_lemin *lemin);
void	init_rooms(t_room *room);

/*
** Parser functions
*/

char	**parser_file(char **spl);
void	count_items(char **split_file, int lines_count, t_lemin *lemin);
int		ant_count(char *line);


/*
** validation functions
*/

void    file_checker(char **split_file, t_lemin *lemin);
void	chck_rooms(int room_num, t_room *rooms);
void	chck_edges(int room_num, t_room *rooms);

/*
** util functions
*/

void	ft_zero(int *arr, size_t size);
int		ft_wс(char const *s, char c);
void	str_init(char **str, char **str2);
void	**ft_free(void **mas, size_t len);
void	ft_exit(char *str);
void	start_end_fail(int start_count, int end_count);

void	ft_free_lemin(t_room *rooms, char **split_file, int room_num, int lines_count, t_path **paths);

/*
** create functions
*/

void	create_rooms(int room_num, t_room *rooms, t_lemin *lemin, char **split_file);
t_room	create_single_room(int id, char *line, t_room *room);
void	create_edges_arr(int edges_num, int *edges, t_lemin *lemin, char **split_file, t_room *rooms);
int		malloc_rooms_edges(t_room *rooms, int count_rooms);
void	init_rooms_edges(t_room *rooms, int len_edges, int *edges, t_lemin *lemin);

/*
** Algorithm
*/
typedef struct		s_path
{
	int				*path;
	int				length;
	int				prior;
	int				*ants;
	int				last_ant;
	struct s_path	*next;
}					t_path;

t_path	*new_path(int *path, int length_path);
void	free_paths(t_path **paths);
void	reverse_paths(t_path **begin_list);
void	add_path(t_path **alst, t_path *neww);
void	set_prior(t_path *paths);

typedef struct	s_dinic
{
	int		*distance;
	int		*queue_stack;
	char	*visited;
	int		end;
	int		i;
}				t_dinic;

int		init_dinic(t_dinic *dinic, int count_v, int end);
int		free_dinic(t_dinic *dinic);

t_path	*dinic(t_room *graph, int count_v, int end);
int		bfs(t_room *graph, size_t count_v, int *distance, int *queue);

int		find_path(int start, int end, t_room *graph, t_dinic vars);
int		check_vertex(int *start, int *top, t_dinic *vars, int u);
int		stack_pop(int *i, int *top, int *start, int *stack);

int		*set_path(int len, int *stack_path, t_room *graph, int end);

/*
** Output
*/
void	send_ants(t_room *graph, int count_ants, t_path *paths);
int		step_all(t_path *current, t_room *graph, int *move);
int		move_ants(t_path *path, t_room *graph, int *move);
int		set_ant(t_path *paths, int ant, t_room *graph, int *move);
void	print_n(int *move);
#endif

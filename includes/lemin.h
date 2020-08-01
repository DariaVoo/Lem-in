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

/* Парсинг */
#define FILE_READ_SIZE 8192

typedef struct      s_lemin
{
	int             ant_num;
	int             room_num;
	int             edges_num;
	int             start_num;
	int             end_num;
	int             lines_count;
}                   t_lemin;

typedef struct s_room
{
	int id;
	char *name;
	int x;
	int y;
	int ed_num;
	int index_edge;
	int *edges;// массив номеров (id) смежных вершин
} t_room;

/*
** Init functions
*/

void    init_lemin(t_lemin *lemin);
void    init_rooms(t_room *room);

/*
** Parser functions
*/

char    **parser_file(char **spl);
void count_items(char **spl_f, int lines_count, t_lemin *lemin);
int ant_count(char *line);


/*
** validation functions
*/

void    file_checker(char **spl_f, t_lemin *lemin);
void	chck_rooms(int room_num, t_room *rooms);
void chck_edges(int room_num, t_room *rooms);
void    count_room_edges(int k, int *edges, t_room *rooms, t_lemin *lemin, char **lines);

/*
** util functions
*/

int	ft_wc(char const *s, char c);
void str_init(char **str, char **str2);
void	**ft_free(void **mas, size_t len);
void ft_exit(char *str);
int     ft_start(t_lemin *lemin, int start_count, int i);
int     ft_end(t_lemin *lemin, int end_count, int i);
void start_end_fail(int start_count, int end_count);
void chk_edge_name(int find_1, int find_2);
void ft_free_lemin(t_room *rooms, char **spl_f, int room_num, int lines_count, t_path **paths);

/*
** create functions
*/

void create_rooms(int room_num, t_room *rooms, t_lemin *lemin, char **spl_f);
t_room create_single_room(int id, char *line, t_room *room);
void create_edges_arr(int *edges, t_lemin *lemin, char **spl_f, t_room *rooms);
int malloc_rooms_edges(t_room *rooms, int count_rooms);
void init_rooms_edges(t_room *rooms, int len_edges, int *edges, t_lemin *lemin);
int add_edge(t_room *rooms, int id_find);

/* Логика и вывод ответа*/

void ft_zero(int *arr, size_t size);

void send_ants(t_room *graph, int count_ants, t_path *paths);
int move_ants(t_path *path, t_room *graph);
int set_ant(t_path *paths, int ant, t_room *graph);

void	add_path(t_path **alst, t_path *neww);
t_path *new_path(int *path, int length_path);
void free_paths(t_path **paths);
void		reverse_paths(t_path **begin_list);
void set_prior(t_path *paths);

int *set_path(int len, int *stack_path, t_room *graph, int end);

t_path *dinic(t_room *graph, size_t count_v);
int bfs(t_room *graph, size_t count_v, int *distance, int *queue);
int find_path(int start, int end, t_room *graph, int *distance, char *visited, int *stack);

void print_path(int *arr, int len);
void print_arr(int *arr, size_t size);
void print_graph(int **graph, size_t size);

#endif

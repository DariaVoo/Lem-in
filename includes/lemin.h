/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:56:16 by erodd             #+#    #+#             */
/*   Updated: 2020/08/02 17:48:31 by erodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct		s_room
{
	int		id;
	char	*name;
	int		x;
	int		y;
	int		ed_num;
	int		index_edge;
	int		*edges;
}					t_room;

typedef struct		s_count
{
	int				k;
	char			**lines;
}					t_count;

/*
** Init functions
*/

void			init_lemin(t_lemin *lemin);
void			init_rooms(t_room *room);

/*
** Parser functions
*/

char			**parser_file(char **spl, t_lemin *lemin);
void			start_end_count(char **spl_f, t_lemin *lemin);
int				ant_count(char *line);
t_room			*parse_lemin(t_lemin *lemin, t_room *rooms);
int				correct_room(char *str, t_lemin *lemin);
int				correct_edge(char *str, t_lemin *lemin);
void			init_rooms_edges(t_room *rooms, int l_edges, int *edges, t_lemin *lemin);

/*
** validation functions
*/

int				correct_line(char *str, t_lemin *lemin);
void			file_checker(char **spl_f, t_lemin *lemin);
t_room			*make_rooms(t_room *rooms, t_lemin *lemin);
void			chck_rooms(int room_num, t_room *rooms);
void			chck_edges(int room_num, t_room *rooms);
void			count_room_edges(t_count count, int *edges, t_room *rooms, t_lemin *lemin);

/*
** util functions
*/

void			ft_zero(int *arr, size_t size);
int				ft_wc(char const *s, char c);
void 			str_init(char **str, char **str2, char **str3);
void			**ft_free(void **mas, size_t len);
void			ft_exit(char *str);
int     		ft_start(t_lemin *lemin, int start_count, int i);
int     		ft_end(t_lemin *lemin, int end_count, int i);
void 			start_end_fail(int start_count, int end_count);
void 			chk_edge_name(int find_1, int find_2);
char			*ft_strjoin_n(char const *s1, char const *s2);
static int		put_new_line(char **vault, char **line, int fd, int bytes);
int				get_next_line_q(const int fd, char **line);

/*
** create functions
*/

void			create_rooms(int room_num, t_room *rooms, t_lemin *lemin, char **spl_f);
t_room			create_single_room(int id, char *line, t_room *room);
void			create_edges_arr(int *edges, t_lemin *lemin, char **spl_f, t_room *rooms);
int				malloc_rooms_edges(t_room *rooms, int count_rooms);
void			init_rooms_edges(t_room *rooms, int len_edges, int *edges, t_lemin *lemin);
int				add_edge(t_room *rooms, int id_find);

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

t_path			*new_path(int *path, int length_path);
void			free_paths(t_path **paths);
void			reverse_paths(t_path **begin_list);
void			add_path(t_path **alst, t_path *neww);
void			set_prior(t_path *paths);

typedef struct	s_dinic
{
	int		*distance;
	int		*queue_stack;
	char	*visited;
	int		end;
	int		i;
}				t_dinic;

int				init_dinic(t_dinic *dinic, int count_v, int end);
int				free_dinic(t_dinic *dinic);

t_path			*dinic(t_room *graph, int count_v, int end);
int				bfs(t_room *graph, size_t count_v, int *distance, int *queue);

int				find_path(int start, int end, t_room *graph, t_dinic vars);
int				check_vertex(int *start, int *top, t_dinic *vars, int u);
int				stack_pop(int *i, int *top, int *start, int *stack);

int				*set_path(int len, int *stack_path, t_room *graph, int end);

/*
** Output
*/
void			send_ants(t_room *graph, int count_ants, t_path *paths);
int				step_all(t_path *current, t_room *graph, int *move);
int				move_ants(t_path *path, t_room *graph, int *move);
int				set_ant(t_path *paths, int ant, t_room *graph, int *move);
void			print_n(int *move);

void 			ft_free_lemin(t_room *rooms, int r_num, t_path **paths);
#endif

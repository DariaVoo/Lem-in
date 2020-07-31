#include "lemin.h"

void    file_checker(char **split_file, t_lemin *lemin)
{
    int     lines_count;
    int num_rooms;
    int ant_num;

    lines_count = 0;
    while (split_file[lines_count])
        lines_count++;
    lemin->lines_count = lines_count;
    lemin->ant_num = ant_count(split_file[0]);
    count_items(split_file, lines_count, lemin);
}

void create_rooms(int room_num, t_room *rooms, t_lemin *lemin, char **split_file)
{
    int i;
    int room_id;

    i = 1;
    room_id = 1;
    while (i < lemin->lines_count)
    {
        if (ft_word_counter(split_file[i], ' ') == 3)
        {
            if (i == lemin->start_num)
                rooms[0] = create_single_room(0, split_file[i], &rooms[0]);
            else if (i == lemin->end_num)
                rooms[room_num - 1] = create_single_room(lemin->room_num - 1, split_file[i], \
                &rooms[lemin->room_num - 1]);
            else
            {
                rooms[room_id] = create_single_room(room_id, split_file[i], &rooms[room_id]);
                room_id++;
            }
        }
        i++;
    }
}

t_room create_single_room(int id, char *line, t_room *room)
{
    char    **lines;
    int     i;

    i = 0;
    lines = ft_strsplit(line, ' ');
    room->id = id;
    room->name = ft_strdup(lines[0]);
    while (ft_isdigit(lines[1][i]) || lines[1][i] == '-')
		i++;
	if (lines[1][i])
		ft_exit("Incorrect coordinates\n");
    i = 0;
    while (ft_isdigit(lines[2][i]) || lines[2][i] == '-')
		i++;
	if (lines[2][i])
		ft_exit("Incorrect coordinates\n");
    room->x = ft_atoi(lines[1]);
    room->y = ft_atoi(lines[2]);
    ft_free((void**)lines, 3);

    return (*room);
}

void	chck_rooms(int room_num, t_room *rooms)
{
    int i;
    int j;

    i = 0;
    while (i < room_num)
    {
        if (rooms[i].name[0] == 'L' || rooms[i].name[0] == '#')
            ft_exit("incorrect ROOM name\n");
        j = i + 1;
        while (j < room_num)
        {
            if (ft_strcmp(rooms[i].name, rooms[j].name) == 0)
            {
                // ft_printf("%s --- %s\n", rooms[i].name, rooms[j].name);
                ft_exit("same ROOM name\n");
            }
            j++;
        }
        i++;
    }
}

void create_edges_arr(int edges_num, int *edges, t_lemin *lemin, char **split_file, t_room *rooms)
{
    int j;
    int i;
    int k;
    int id_find;
    char **lines;
    int find_1;
    int find_2;


    i = lemin->room_num;
    k = 0;
    while (i < lemin->lines_count)
    {
        j = 1;
        lines = ft_strsplit(split_file[i], '-');
        if (ft_word_counter(split_file[i], '-') == 2)
        {
            id_find = 0;
            find_1 = 0;
            find_2 = 0;
            //ft_printf("I'm LINE NUMBER! - %d\n", i);
            while (id_find < lemin->room_num)
            {
                if (find_1 == 0 && ft_strcmp(rooms[id_find].name, lines[0]) == 0)
                {
                    edges[k] = rooms[id_find].id;
                    rooms[id_find].num_of_edges++;
                    k++;
                    find_1 = 1;
                }
                if (find_2 == 0 && ft_strcmp(rooms[id_find].name, lines[1]) == 0)
                {
                    edges[k] = rooms[id_find].id;
                    rooms[id_find].num_of_edges++;
                    //ft_printf("I'm working! - %d\n", edges[k]);
                    k++;
                    find_2 = 1;
                }
                if (find_1 == 1 && find_2 == 1)
                {
                    break;
                }
                id_find++;
            }
            if (find_1 == 0 || find_2 == 0)
                ft_exit("Incorrect EDGE name\n");
        }
        ft_free((void**)lines, 2);
        i++;
    }
    
}

void init_rooms_edges(t_room *rooms, int len_edges, int *edges, t_lemin *lemin)
{
    int i;

    i = 0;
    while (i < len_edges)
    {
        int room_1;
        rooms[edges[i + 1]].edges[rooms[edges[i + 1]].index_edge] = edges[i];
        rooms[edges[i + 1]].index_edge++;
        rooms[edges[i]].edges[rooms[edges[i]].index_edge] = edges[i + 1];
        rooms[edges[i]].index_edge++;
        i += 2;
    }
}

void chck_edges(int room_num, t_room *rooms)
{
    int i;
    int j;
    int k;

    i = 0;
    while (i < room_num)
    {
        j = 0;
        while (j < rooms[i].num_of_edges)
        {
            k = j + 1;
            while (k < rooms[i].num_of_edges && j < rooms[i].num_of_edges - 1)
            {
                if (rooms[i].edges[j] == rooms[i].edges[k])
                    ft_exit("Same links");
                k++;
            }
            if (rooms[i].id == rooms[i].edges[j])
                ft_exit("ROOM links theirselves\n");
            j++;
        }
        i++;
    }
}

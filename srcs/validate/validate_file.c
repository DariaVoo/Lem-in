#include "lemin.h"

void    file_checker(char **spl_f, t_lemin *lemin)
{
    int     lines_count;
    int num_rooms;
    int ant_num;

    lines_count = 0;
    while (spl_f[lines_count])
        lines_count++;
    lemin->lines_count = lines_count;
    lemin->ant_num = ant_count(spl_f[0]);
    count_items(spl_f, lines_count, lemin);
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
        while (j < rooms[i].ed_num)
        {
            k = j + 1;
            while (k < rooms[i].ed_num && j < rooms[i].ed_num - 1)
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

void    count_room_edges(int k, int *edges, t_room *rooms, t_lemin *lemin, char **lines)
{
    int id_find;
    int find_1;
    int find_2;

    id_find = 0;
    find_1 = 0;
    find_2 = 0;
    while (id_find < lemin->room_num)
    {
        if (find_1 == 0 && ft_strcmp(rooms[id_find].name, lines[0]) == 0)
        {
            edges[k] = add_edge(rooms, id_find);
            k++;
            find_1 = 1;
        }
        if (find_2 == 0 && ft_strcmp(rooms[id_find].name, lines[1]) == 0)
        {
            edges[k] = add_edge(rooms, id_find);
            k++;
            find_2 = 1;
        }
        //if (find_1 == 1 && find_2 == 1)
        //    break;
        id_find++;        
    }
    chk_edge_name(find_1, find_2);
}

void chk_edge_name(int find_1, int find_2)
{
    if (find_1 == 0 || find_2 == 0)
        ft_exit("Incorrect EDGE name\n");
}

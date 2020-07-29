#include "lemin.h"

void    file_checker(char **split_file, t_lemin *lemin)
{
    int     lines_count;
    int num_rooms;
    int ant_num;

    lines_count = 0;
    while (split_file[lines_count])
    {
        //ft_printf("%s\n", split_file[lines_count]);
        lines_count++;
    }
    ft_printf("Count lines%d\n", lines_count);
    lemin->lines_count = lines_count;

    // Считаем муравьев
    lemin->ant_num = ant_count(split_file[0]);
    ft_printf("Count ant %d\n", lemin->ant_num);

    // Считаем комнаты
    count_items(split_file, lines_count, lemin);
    ft_printf("Count rooms %d\n", lemin->room_num);

}

void create_rooms(int room_num, t_room *rooms, t_lemin *lemin, char **split_file)
{
    int i;
    int room_id;

    i = 1;
    room_id = 1;
    //rooms = (t_room *)malloc(sizeof(t_room)*lemin->room_num);
    while (i < lemin->lines_count)
    {
        //ft_printf("%s\n", split_file[i]);
        if (ft_word_counter(split_file[i], ' ') == 3 && split_file[i][0] != 'L' && split_file[i][0] != '#')
        {
            if (i == lemin->start_num)
            {
                rooms[0] = create_single_room(0, split_file[i], &rooms[0]);
            }
            else if (i == lemin->end_num)
            {
                rooms[room_num - 1] = create_single_room(lemin->room_num - 1, split_file[i], &rooms[lemin->room_num - 1]);
            }
            else
            {
                rooms[room_id] = create_single_room(room_id, split_file[i], &rooms[room_id]);
                room_id++;
            }
        }
        //ft_printf("my id: %d, my name: %s, my X: %d, my Y: %d\n", rooms[i].id, rooms[i].name, rooms[i].x, rooms[i].y);
        i++;
    }
}

t_room create_single_room(int id, char *line, t_room *room)
{
    //ft_printf("Here!");
    char    **lines;
    int     i;

    i = -1;
    lines = ft_strsplit(line, ' ');
    
    room->id = id;
    room->name = ft_strdup(lines[0]);
    room->x = ft_atoi(lines[1]);
    room->y = ft_atoi(lines[2]);

    ft_free((void**)lines, 3);
    //ft_printf("my id: %d, my name: %s, my X: %d, my Y: %d\n", room->id, room->name, room->x, room->y);

    return (*room);
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
        }
        ft_free((void**)lines, 2);
        i++;
        //ft_printf("I'm LINE NUMBER! - %d\n", i);
    }
    
}

int malloc_rooms_edges(t_room *rooms, int count_rooms)
{
    int i;

    i = 0;
    while (i < count_rooms)
    {
        if (!(rooms[i].edges = (int *)malloc(sizeof(int) * rooms[i].num_of_edges)))
            return (0);
		if (!(rooms[i].flow = (int *)malloc(sizeof(int) * rooms[i].num_of_edges)))
			return (0);
		ft_bzero(rooms[i].flow, rooms[i].num_of_edges);
        i++;
    }
    return (1);
}

void init_rooms_edges(t_room *rooms, int len_edges, int *edges, t_lemin *lemin)
{
    int i;
    int index_in_da_room;

    i = 0;
    //start = 0; // 
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
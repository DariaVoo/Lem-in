#include "lemin.h"

// Считаем муравьев
int ant_count(char *line)
{
    int ant_count;

    ant_count = ft_atoi(line);

    return (ant_count);
}

// Считаем комнаты и ищем номера линий, где находится старт и финиш
void count_items(char **split_file, int lines_count, t_lemin *lemin)
{
    int i;

    i = 1;
    while (i < lines_count)
    {
        if (ft_word_counter(split_file[i], ' ') == 3 && split_file[i][0] != 'L' && split_file[i][0] != '#')
            lemin->room_num++;
        if (ft_strstr(split_file[i], "##start"))
            lemin->start_num = i + 1;
        if (ft_strstr(split_file[i], "##end"))
            lemin->end_num = i + 1;
        if (ft_word_counter(split_file[i], '-') == 2)
            lemin->edges_num++;
        i++;
    }

    //return (num_rooms);
}


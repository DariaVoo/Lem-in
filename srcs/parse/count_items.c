#include "lemin.h"

// Считаем муравьев
int ant_count(char *line)
{
    int ant_count;
	int	i;

	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	if (line[i])
		ft_exit("Incorrect number of ANTS\n");
	ant_count = ft_atoi(line);
	if (ant_count < 1 || ant_count > INT32_MAX)
		ft_exit("Incorrect number of ANTS\n");
	ft_putnbr(ant_count);
	ft_putchar('\n');
	
    return (ant_count);
}

// Считаем комнаты и ищем номера линий, где находится старт и финиш
void count_items(char **split_file, int lines_count, t_lemin *lemin)
{
    int i;
    int start_count;
    int end_count;

    i = 1;
    start_count = 0;
    end_count = 0;
    while (i < lines_count)
    {
        if (ft_word_counter(split_file[i], ' ') == 3)
            lemin->room_num++;
        if (ft_strcmp(split_file[i], "##start\0") == 0 && ft_word_counter(split_file[i + 1], ' ') == 3)
        {
            lemin->start_num = i + 1;
            start_count++;
        }
        if (ft_strcmp(split_file[i], "##end\0") == 0 && ft_word_counter(split_file[i + 1], ' ') == 3)
        {
            lemin->end_num = i + 1;
            end_count++;
        }
        if (ft_word_counter(split_file[i], '-') == 2 && ft_word_counter(split_file[i], ' ') != 3)
            lemin->edges_num++;
        i++;
    }
    start_end_fail(start_count, end_count);
}


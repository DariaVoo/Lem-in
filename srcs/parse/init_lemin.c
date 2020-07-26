#include "lemin.h"

void    init_lemin(t_lemin *lemin)
{
    lemin->ant_num = 0;
    lemin->edges_num = 0;
    lemin->end_num = 0;
    lemin->room_num = 0;
    lemin->start_num = 0;
    lemin->lines_count = 0;
}

void    init_rooms(t_room *room)
{
    room->id = 0;
    room->name = NULL;
    room->x = 0;
    room->y = 0;
    room->num_of_edges = 0;
    room->index_edge = 0;
    room->edges = NULL;
}
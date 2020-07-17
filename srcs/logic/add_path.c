#include "lemin.h"

void	add_path(t_path **alst, t_path *neww)
{
	neww->next = *alst;
	*alst = neww;
}
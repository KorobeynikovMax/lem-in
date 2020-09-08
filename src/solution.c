/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 15:19:24 by bedavis           #+#    #+#             */
/*   Updated: 2020/09/05 15:19:26 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				set_all_visit(t_lem *lem, int visit_flag)
{
	t_room			*room;

	room = lem->map;
	while (room != NULL)
	{
		room->visit_flag = visit_flag;
	}
}

void 				addInPath(t_room_address *resultPath, t_room *room)
{


}

int		*recursion(t_room *room, t_room_address *resultPath)
{
	t_room_address	*links;

	links = room->links;
	if (links == NULL)
		return (0);
	while (links != NULL)
	{
		if (links->address->start_end_flag == END_ROOM_MODIFIER)
		{
			addInPath(resultPath, room);
			delete_links(room, links);
			return (1);
		} else {
			links->address->visit_flag = 1;
			recursion(links->address, resultPath);
		}
		links = links->next;
	}


}

void				solve(t_lem *lem)
{
	t_paths_list	*pathsList;

	t_room_address	*resultPath;

	addInPath(resultPath, lem->end_room);
	recursion(lem->start_room, resultPath);



    ft_putstr("here print result\n");
    return;
}


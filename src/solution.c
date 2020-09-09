/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 15:19:24 by bedavis           #+#    #+#             */
/*   Updated: 2020/09/09 20:22:55 by maxim            ###   ########lyon.fr   */
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

int					put_numbers_from_links(t_room_address *address, int index)
{
	t_room_address *tek;

	tek = address;
	while (tek != NULL)
	{
		if (tek->address->visit_flag == 0)
			tek->address->visit_flag = index + 1;
		if (tek->address->start_end_flag == END_ROOM_MODIFIER)
			return (1);
		tek = tek->next;
	}
	return (0);
}

void				put_numbers(t_lem *lem)
{
	t_room *tmp;
	int index;
	int isEnd;

	tmp = lem->map;
	index = 1;
	isEnd = 0;
	lem->start_room->visit_flag = index;
	while (!isEnd)
	{
		while (tmp != NULL)
		{
			if (tmp->visit_flag == index)
			{
				if (put_numbers_from_links(tmp->links, index))
					isEnd = 1;
			}
			tmp = tmp->next;
		}
		index++;
		tmp = lem->map;
	}
}

void				addInRoomList(t_room_address **list, t_room *room)
{
	t_room_address  *tmp;

	tmp = (t_room_address *)malloc(sizeof(t_room_address));
	tmp->address = room;
	tmp->next = *list;
	*list = tmp;
}

t_room				*findNext(t_room *room, int index)
{
	t_room_address *tmp;

	tmp = room->links;
	while (tmp != NULL)
	{
		if (tmp->address->visit_flag == index)
			return (tmp->address);
		tmp = tmp->next;
	}
	return (NULL);
}

t_room_address 		*findPath(t_lem *lem)
{
	t_room_address *result;
	t_room *next;
	int index;

	result = NULL;
	if (lem->end_room->visit_flag == 0)
		return (NULL);
	index = lem->end_room->visit_flag - 1;
	addInRoomList(&result, lem->end_room);
	next = lem->end_room;
	while (1)
	{
		next = findNext(next, index);
		if (next == NULL)
			break;
		addInRoomList(&result, next);
		index--;
	}
	return (result);
}

void				find_path_cikly(t_lem *lem, t_room_address **resultPath)
{
	t_room_address *curPath;


	//while(1)
		put_numbers(lem);
		*resultPath = findPath(lem);
		//set_all_visit(lem, 0);
		//if (curPath == NULL)
		//	break;
		//else
		//	print_path(curPath);



}

void				ft_printPath(t_room_address *path)
{
	t_room_address *tmp;

	tmp = path;
	while (tmp != NULL)
	{
		ft_putstr(tmp->address->name);
		ft_putstr("->");
		tmp = tmp->next;
	}
}

void				solve(t_lem *lem)
{
	t_paths_list	*pathsList;
	t_room_address	*resultPath;

	resultPath = NULL;
	find_path_cikly(lem, &resultPath);
	//addInPath(resultPath, lem->end_room);
	//recursion(lem->start_room, resultPath);



	ft_putstr("here print result\n");
	ft_printPath(resultPath);
	return ;
}


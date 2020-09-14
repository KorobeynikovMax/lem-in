/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 17:10:48 by bedavis           #+#    #+#             */
/*   Updated: 2020/09/14 13:02:07 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void 				add_in_paths_list(t_paths_list **list, t_room_address *cur)
{
	t_paths_list *tmp;

	tmp = (t_paths_list *)malloc(sizeof(t_paths_list));
	if (tmp == NULL)
		exit_with_malloc_error();
	tmp->ants_queue = 0;
	tmp->active_ants = 0;
	tmp->rooms_count = 0;
	tmp->path = cur;
	tmp->next = *list;
	*list = tmp;
}

t_room				*find_next(t_room *room, int index)
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

t_room_address 		*find_path(t_lem *lem)
{
	t_room_address *result;
	t_room *next;
	t_room *prev;
	int index;

	result = NULL;
	if (lem->end_room->visit_flag == 0)
		return (NULL);
	index = lem->end_room->visit_flag - 1;
	addInRoomList(&result, lem->end_room);
	prev = lem->end_room;
	while (1)
	{
		next = find_next(prev, index);
		if (next == NULL)
			break;
		addInRoomList(&result, next);
		if (prev->start_end_flag == 0)
			prev->visit_flag = -1;
		prev = next;
		index--;
	}
	if (result != NULL && result->address->start_end_flag == START_ROOM_MODIFIER)
		lem->hasPath = 1;
	return (result);
}

t_room_address		*get_path_by_index(t_paths_list *paths, int index)
{
	int				i;
	t_paths_list	*p;
	t_room_address	*path;

	i = 0;
	p = paths;
	while (p != NULL)
	{
		path = p->path;
		if (i == index)
			return (path);
		i++;
		p = p->next;
	}
	return (NULL);
}

t_paths_list		*get_shortest_path_list(t_paths_list *head)
{
	t_paths_list	*curr;
	t_paths_list	*shortest_path_list;
	int				count_steps;
	int				min_steps;

	curr = head;
	min_steps = curr->rooms_count + curr->ants_queue;
	shortest_path_list = curr;
	curr = curr->next;
	while (curr != NULL)
	{
		count_steps = curr->rooms_count + curr->ants_queue;
		if (count_steps < min_steps)
		{
			min_steps = count_steps;
			shortest_path_list = curr;
		}
		curr = curr->next;
	}
	curr = NULL;
	return (shortest_path_list);
}

void				reverse_path_list(t_paths_list **head)
{
	t_paths_list		*curr;
	t_paths_list		*next;
	t_paths_list		*prev;

	if (*head == NULL)
		return;
	prev = NULL;
	curr = *head;
	while(curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}
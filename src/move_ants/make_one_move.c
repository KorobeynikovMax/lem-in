/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_one_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 13:40:16 by wanton            #+#    #+#             */
/*   Updated: 2020/09/16 14:56:16 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			print_ant(t_room_address *room)
{
	ft_putstr(ANT_NAME);
	ft_putnbr(room->visitor_number);
	ft_putchar('-');
	ft_putstr(room->address->name);
	ft_putchar(' ');
}

void			change_path_list_param(t_lem *lem, t_paths_list *path,
							t_room_address *room)
{
	if (lem->start_room == room->address)
	{
		path->ants_queue--;
		path->active_ants++;
	}
	if (lem->end_room == room->next->address)
	{
		path->active_ants--;
		path->path->visitor_number = 0;
	}

}

void			clear_end_room(t_room_address *path, t_lem *lem)
{
	if (path->address == lem->end_room)
		path->visitor_number = 0;
}

void			move_ant(t_room_address *room, t_paths_list *path, t_lem *lem)
{
	change_path_list_param(lem, path, room);
	room->next->visitor_number = room->visitor_number;
	room->visitor_number = 0;
}

t_room_address	*find_ant_for_move(t_paths_list *path)
{
	t_room_address		*curr;

	curr = path->path;
	while (curr->next != NULL)
	{
		if (curr->visitor_number != 0 && curr->next->visitor_number == 0)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

int				count_ants_to_move(t_room_address *path)
{
	int					count_ants;
	t_room_address		*current;

	count_ants = 0;
	current = path;
	while (current != NULL)
	{
		if (current->visitor_number != 0)
			count_ants++;
		current = current->next;
	}
	return (count_ants);
}

void			move_and_print_existing_ants(t_lem *lem, t_paths_list *head)
{
	int					count_ants;
	t_room_address		*curr_room;

	count_ants = count_ants_to_move(head->path);
	while (count_ants-- > 0)
	{
		curr_room = find_ant_for_move(head);
		move_ant(curr_room, head, lem);
		print_ant(curr_room->next);
		clear_end_room(curr_room->next, lem);
	}
}

void			put_new_ant_on_path(t_paths_list *path, int *ant_num)
{
	path->path->next->visitor_number = *ant_num;
	(*ant_num)++;
	print_ant(path->path->next);
}

int				check_new_ant(t_paths_list *head)
{
	if (head->ants_queue > 0
	&& head->path->next->visitor_number == 0)
		return (1);
	return (0);
}

int				make_one_move(t_lem *lem, t_paths_list *head, int *ant_num)
{
	int				flag;
	t_paths_list	*curr;

	flag = 1;
	curr = head;
	while (curr != NULL)
	{
		if (curr->active_ants == 0 && curr->ants_queue > 0)
		{
			change_path_list_param(lem, curr, curr->path);
			put_new_ant_on_path(curr, ant_num);
			flag = 0;
		}
		else if (curr->active_ants > 0)
		{
			move_and_print_existing_ants(lem, curr);
			if (check_new_ant(curr))
			{
				change_path_list_param(lem, curr, curr->path);
				put_new_ant_on_path(curr, ant_num);
			}
			flag = 0;
		}
		curr = curr->next;
	}
	return (flag);
}

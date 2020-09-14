/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transport_ants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:32:28 by wanton            #+#    #+#             */
/*   Updated: 2020/09/14 14:20:36 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			print_ant(t_room_address *room)
{
	ft_putstr(ANT_NAME);
	ft_putnbr(room->visitor_number);
	ft_putchar(' ');
}

void			change_path_list_param(t_lem *lem, t_paths_list *path)
{
	if (lem->start_room == path->path->address)
	{
		path->ants_queue--;
		path->active_ants++;
	}
	if (lem->end_room == path->next->path->address)
	{
		path->active_ants--;
		path->path->visitor_number = END_ROOM_NUMBER;
	}

}

void			put_new_ant(t_paths_list *path, int ant_num)
{
	path->path->visitor_number = ant_num;
}

void			move_solo_ant(t_room_address *room, t_paths_list *path,
					t_lem *lem, int *ant_num)
{
	change_path_list_param(lem, path);
	if (room->address == lem->start_room)
	{
		put_new_ant(path, *ant_num);
		(*ant_num)++;
	}
	room->next->visitor_number = room->visitor_number;
	room->visitor_number = 0;
}

t_room_address	*find_ant_for_move(t_paths_list *path)
{
	t_room_address		*curr_room;
	
	curr_room = path->path;
	while (curr_room->next != NULL)
	{
		if (curr_room->next->visitor_number == 0)
			break ;
		curr_room = curr_room->next;
	}
	if (curr_room->next->visitor_number == 0)
		return (curr_room);
	else
		return (NULL);
}

int			move_and_print_existing_ants(t_lem *lem, t_paths_list *path,
									int *ant_num)
{
	int					flag;
	t_room_address		*curr_room;

	flag = 0;
	curr_room = find_ant_for_move(path);
	while (curr_room != NULL)
	{
		flag = 1;
		move_solo_ant(curr_room, path, lem, ant_num);
		print_ant(curr_room->next);
		curr_room = find_ant_for_move(path);
	}
	return (flag);
}

int				transport_ants(t_lem *lem, t_paths_list *path, int *ant_num)
{
	if (path->ants_queue == 0)
	{
		change_path_list_param(lem, path);
		put_new_ant(path, *ant_num);
		(*ant_num)++;
		print_ant(path->path);
		return (1);
	}
	else
		return (move_and_print_existing_ants(lem, path, ant_num));
}

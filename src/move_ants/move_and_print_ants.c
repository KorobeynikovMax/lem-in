/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_and_print_ants.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:18:19 by wanton            #+#    #+#             */
/*   Updated: 2020/09/16 15:16:20 by wanton           ###   ########.fr       */
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

int				is_need_new_ant(t_paths_list *head)
{
	if (head->ants_queue > 0 && head->path->next->visitor_number == 0)
		return (1);
	return (0);
}

int				make_one_move(t_lem *lem, t_paths_list *head, int *ant_num)
{
	int				is_ants_end;
	t_paths_list	*current;

	is_ants_end = 1;
	current = head;
	while (current != NULL)
	{
		if (is_new_path(current))
		{
			put_new_ant_on_path(lem, current, *ant_num);
			(*ant_num)++;
			is_ants_end = 0;
		}
		else if (current->active_ants > 0)
		{
			move_group_ants(lem, current);
			if (is_need_new_ant(current))
			{
				put_new_ant_on_path(lem, current, *ant_num);
				(*ant_num)++;
			}
			is_ants_end = 0;
		}
		current = current->next;
	}
	return (is_ants_end);
}

void		move_and_print_ants(t_lem *lem, t_paths_list *head)
{
	int					is_ants_end;
	int					ant_number;

	ant_number = 1;
	is_ants_end = 0;
	while (is_ants_end == 0)
	{
		is_ants_end = make_one_move(lem, head, &ant_number);
		ft_putchar('\n');
	}
}
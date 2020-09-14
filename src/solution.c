/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 15:19:24 by bedavis           #+#    #+#             */
/*   Updated: 2020/09/14 12:59:36 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	ft_putstr("\n");
}

void				find_path_cikly(t_lem *lem, t_paths_list **result_path)
{
	t_paths_list	*result_list;
	t_room_address	*cur_path;
	cur_path = NULL;
	result_list = NULL;
	while (1)
	{
		put_numbers(lem);
		cur_path = find_path(lem);
		set_all_visit(lem, 0);
		if (cur_path == NULL)
			break;
		else
			add_in_paths_list(&result_list, cur_path);
			//ft_printPath(cur_path);
	}
	*result_path = result_list;
}

void				solve(t_lem *lem)
{
	t_paths_list	*paths_list;

	paths_list = NULL;
	find_path_cikly(lem, &paths_list);
	reverse_path_list(&paths_list);
	ants_distributor(lem, paths_list);
/*
** Посмотреть текущие пути
	ft_putstr("here print result\n");
	ft_printPath(resultPath);
*/
	return ;
}


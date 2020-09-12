/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_and_print_ants.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 16:37:03 by wanton            #+#    #+#             */
/*   Updated: 2020/09/12 16:43:57 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		count_number_of_paths(t_paths_list *first_path)
{
	t_paths_list	*p;
	int				count;

	count = 0;
	p = first_path;
	while (p != NULL)
	{
		p = p->next;
		count++;
	}
	return (count);
}



void	move_and_print_ants(t_lem *lem, t_paths_list *paths)
{

}

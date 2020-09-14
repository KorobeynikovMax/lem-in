/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_distributor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 15:16:57 by wanton            #+#    #+#             */
/*   Updated: 2020/09/14 13:32:24 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				count_number_of_paths(t_paths_list *first_path)
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

void				count_rooms_in_paths(t_paths_list *head)
{
	t_paths_list	*current_path;

	current_path = head;
	while (current_path != NULL)
	{
		current_path->rooms_count = count_rooms(current_path->path);
		current_path = current_path->next;
	}
	//TODO delete this:
	/*current_path = head;
	int i = 0;
	while (current_path)
	{
		ft_putstr("Path ");
		ft_putnbr(i++);
		ft_putstr(" has ");
		ft_putnbr(current_path->rooms_count);
		ft_putstr(" rooms\n");
		current_path = current_path->next;
	}*/
}

//TODO delete this
void			print_numbers(int	*n, int size)
{
	int i;
	
	i = 0;
	while (i < size)
	{
		ft_putstr("size of ");
		ft_putnbr(i + 1);
		ft_putstr(" is ");
		ft_putnbr(n[i]);
		ft_putchar('\n');
		i++;
	}
}

void			create_ants_queue(t_lem *lem, t_paths_list *head)
{
	int				count_ants;
	t_paths_list	*shortest_path;

	count_ants = lem->count_ants;
	while (count_ants > 0)
	{
		shortest_path = get_shortest_path_list(head);
		shortest_path->ants_queue++;
		count_ants--;
	}
}

void	ants_distributor(t_lem *lem, t_paths_list *paths)
{
	int					count_paths;

	count_paths = count_number_of_paths(paths);
	count_rooms_in_paths(paths);
	create_ants_queue(lem, paths);
	move_and_print_ants(lem, paths);
}

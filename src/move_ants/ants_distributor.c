/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_distributor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 15:16:57 by wanton            #+#    #+#             */
/*   Updated: 2020/09/13 17:05:55 by wanton           ###   ########.fr       */
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

int				*count_rooms_in_paths(t_paths_list *paths, int count_paths)
{
	int		i;
	int		*rooms_number;

	i = 0;
	rooms_number = (int *)malloc(sizeof(int) * (count_paths + 1));
	if (rooms_number == NULL)
		exit_with_malloc_error();
	while (i < count_paths)
	{
		rooms_number[i] = count_rooms(get_path_by_index(paths, i));
		i++;
	}
	return (rooms_number);
}

t_ants_position	*create_array_ants_position(t_lem *lem)
{
	int				i;
	t_ants_position	*arr;
	t_ants_position *new_ant;
	t_ants_position *tmp;

	i = 1;
	arr = create_new_ant(lem, i++);
	tmp = arr;
	while (i <= lem->count_ants)
	{
		new_ant = create_new_ant(lem, i++);
		tmp->next = new_ant;
		tmp = new_ant;
	}
	tmp = NULL;
	new_ant = NULL;
	//TODO delete this
	/*tmp = arr;
	while (tmp != NULL)
	{
		ft_putstr("ant ");
		ft_putnbr(tmp->ant_number);
		ft_putstr(" path is ");
		ft_putnbr(tmp->path_number);
		ft_putchar('\n');
		tmp = tmp->next;
	}*/
	return (arr);
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

void	ants_distributor(t_lem *lem, t_paths_list *paths)
{
	int					count_paths;
	int					*rooms_number;
	t_ants_position 	*ants_positions;

	count_paths = count_number_of_paths(paths);
	rooms_number = count_rooms_in_paths(paths, count_paths);
	ants_positions = create_array_ants_position(lem);
	move_and_print_ants()
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:53:34 by bedavis           #+#    #+#             */
/*   Updated: 2020/09/06 15:57:21 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			init_lem(t_lem **lem)
{
	if (!(*lem = (t_lem *)malloc(sizeof(t_lem))))
		exit(1);
	(*lem)->count_ants = 0;
	(*lem)->map = NULL;
	(*lem)->paths = NULL;
	(*lem)->start_room = NULL;
	(*lem)->end_room = NULL;
}

void			print_number_of_ants(t_lem *lem)
{
	ft_putnbr(lem->count_ants);
	ft_putchar('\n');
}

void			print_t_room(t_lem *lem)
{
	t_room		*room;

	room = lem->map;
	while (room != NULL)
	{
		ft_putstr(room->name);
		ft_putchar(' ');
		ft_putnbr(room->x_coord);
		ft_putchar(' ');
		ft_putnbr(room->y_coord);
		ft_putchar('\n');
		room = room->next;
	}
}

int				main()
{
	t_lem 		*lem;

	init_lem(&lem);
	parse_map(lem);
	/*solve(lem);*/
	printf("it works!\n");
	print_number_of_ants(lem);
	print_t_room(lem);
	free_t_lem(lem);
	return (0);
}


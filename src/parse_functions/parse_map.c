/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 16:53:57 by wanton            #+#    #+#             */
/*   Updated: 2020/09/05 17:02:30 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*get_read_line()
{
	char		*line;

	while (1)
	{
		if (ft_get_next_line(0, &line) == -1)
			exit_with_read_error();
		if (line[0] != '#')
			return (line);
		free(line);
	}
}

void		parse_count_ants(t_lem *lem)
{
	char		*line;

	line = get_read_line();
	if (ft_isdigit_str(line) == 0)
		exit_with_not_valid_map();
	lem->count_ants = ft_atoi(line);
	free(line);
}

void		parse_map(t_lem *lem)
{
	parse_count_ants(lem);
}
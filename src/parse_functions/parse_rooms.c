/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 17:39:13 by wanton            #+#    #+#             */
/*   Updated: 2020/09/05 19:26:37 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		looking_for_double(t_lem *lem, char **buff)
{
	t_room	*room;
	int		x_new;
	int		y_new;

	x_new = ft_atoi(buff[1]);
	y_new = ft_atoi(buff[2]);
	room = lem->map;
	while (room != NULL)
	{
		if (ft_strcmp(room->name, buff[0]))
			return (1);
		if (x_new == room->x_coord || y_new == room->y_coord)
			return (1);
		room = room->next;
	}
	return (0);
}
//TODO here leaks
static int		check_valid_room(char *line, t_lem *lem)
{
	char		**buff;

	buff = NULL;
	pft_str_split(&buff, line);
	if (ft_len_char_array(buff) != 3)
		return (1);
	if (buff[0][0] == '\0' || buff[0][0] == 'L')
		return (1);
	if (ft_isdigit_str(buff[1]) == 0 && ft_isdigit_str(buff[2]) == 0)
		return (1);
	if (looking_for_double(lem, buff) == 1)
		return (1);
	return (0);
}

static int		check_modifier(int *start_end_flag, const char *line)
{
	if (ft_strcmp(line, "##start") == 0)
	{
		*start_end_flag = START_ROOM_MODIFIER;
		return (1);
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		*start_end_flag = END_ROOM_MODIFIER;
		return (1);
	}
	return (0);
}

static int		check_valid_comment_and_exit(const char *line)
{
	if (line[0] != '#')
		return (0);
	else if (line[0] == '#' && line[1] != '#')
		return (1);
	exit_with_not_valid_map();
	return (0);
}

char			*parse_rooms(t_lem *lem)
{
	char		*line;
	int			start_end_flag;
	t_room		*last_room;

	start_end_flag = 0;
	line = NULL;
	last_room = NULL;
	while (1)
	{
		if (line)
			free(line);
		pft_get_next_line(DESCRIPTOR, &line);
		if (check_modifier(&start_end_flag, line) == 1)
			continue ;
		if (check_valid_comment_and_exit(line) == 1)
			continue ;
		if (check_valid_room(line, lem) == 1)
			break ;
		add_new_room(&last_room, lem, line, start_end_flag);
		start_end_flag = 0;
	}
	return (line);
}
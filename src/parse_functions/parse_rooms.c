/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 17:39:13 by wanton            #+#    #+#             */
/*   Updated: 2020/09/08 12:00:41 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		looking_for_double_and_exit(t_lem *lem, char *line)
{
	t_room	*room;
	char	**buff;
	int		x_new;
	int		y_new;

	pft_str_split(&buff, line);
	x_new = ft_atoi(buff[1]);
	y_new = ft_atoi(buff[2]);
	room = lem->map;
	while (room != NULL)
	{
		if (ft_strcmp(room->name, buff[0]) == 0)
			exit_with_not_valid_map();
		if (x_new == room->x_coord && y_new == room->y_coord)
			exit_with_not_valid_map();
		room = room->next;
	}
	free_char_buff(buff);
}

int			check_valid_room(char *line, t_lem *lem)
{
	char		**buff;
	int			res;

	buff = NULL;
	res = 0;
	pft_str_split(&buff, line);
	if ((ft_len_char_array(buff) != 3)
	|| (buff[0][0] == '\0')
	|| (buff[0][0] == 'L')
	|| (ft_isdigit_str(buff[1]) == 0)
	|| (ft_isdigit_str(buff[2]) == 0))
		res = 1;
	free_char_buff(buff);
	return (res);
}

int			check_modifier(int *start_end_flag, const char *line)
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

void		check_start_end_room_and_exit(t_lem *lem)
{
	if (lem->start_room == NULL
	|| lem->end_room == NULL
	|| lem->start_room == lem->end_room)
		exit_with_not_valid_map();
}

char		*parse_rooms(t_lem *lem)
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
		if (check_comment(line) == 1)
			continue ;
		if (check_valid_room(line, lem) == 1)
			break ;
		looking_for_double_and_exit(lem, line);
		add_new_room(&last_room, lem, line, start_end_flag);
		start_end_flag = 0;
	}
	check_start_end_room_and_exit(lem);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseLinkRooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 15:05:00 by bedavis           #+#    #+#             */
/*   Updated: 2020/09/03 15:05:02 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					free_split(char **split)
{
	free(split[0]);
	free(split[1]);
	free(split);
	return (0);
}

int					isValidLink(char *line, char **r1, char **r2)
{
	char			**split;
	char			*p;

	if (*line == '#')
		return (1);
	split = ft_strsplit(line, '-');
	if ((!split[0] || split[0][0] == 'L') || (!split[1] || split[1][0] == 'L')
					|| !(split[2] == NULL))
		return (free_split(split));
	p = split[0];
	while (*p && !(*p == '\r' || *p == '\n' || *p == ' ' || *p == '\t'))
		p++;
	if (*p == '\r' || *p == '\n' || *p == ' ' || *p == '\t')
		return (free_split(split));
	p = split[1];
	while (*p && !(*p == '\r' || *p == '\n' || *p == ' ' || *p == '\t'))
		p++;
	if (*p == '\r' || *p == '\n' || *p == ' ' || *p == '\t')
		return (free_split(split));
	*r1 = split[0];
	*r2 = split[1];
	free(split);
	return (1);
}

/*
** return the room with name r1 or NULL
*/

t_room				*find_room(t_lem *lem, char *room)
{
	t_room			*tmp;

	tmp = lem->map;
	if (tmp == NULL)
		return (NULL);
	while (!(ft_strcmp(tmp->name, room) == 0))
	{
		if (tmp->next == NULL)
			return (NULL);
		tmp = tmp->next;
	}
	return (tmp);
}

/*
** create links in room1 and room2
*/

static void			addLink(t_lem *lem, char *r1, char *r2)
{
	t_room			*p1;
	t_room			*p2;
	t_room_address  *a;
	t_room_address  *b;
	t_room_address  *tmp;

	p1 = find_room(lem,r1);
	p2 = find_room(lem, r2);
	if (p1 == NULL || p2 == NULL || p1 == p2)
		return;
	a = (t_room_address *)malloc(sizeof(t_room_address));
	a->address = p2;
	a->next = NULL;
	tmp = p1->links;
	p1->links = a;
	p1->links->next = tmp;
	b = (t_room_address *)malloc(sizeof(t_room_address));
	b->address = p1;
	b->next = NULL;
	tmp = p2->links;
	p2->links = b;
	p2->links->next = tmp;
	free(r1);
	free(r2);
}

void				parse_links_rooms(t_lem *lem, char *line)
{
	char			*r1;
	char			*r2;

	if (!isValidLink(line, &r1, &r2))
		exit_with_not_valid_map();
	else
		addLink(lem, r1, r2);
	while (1)
	{
		if (line)
			free(line);
		pft_get_next_line(DESCRIPTOR, &line);
		if (line == NULL || line[0] == '\0')
		{
			free(line);
			break;
		}
		if (!isValidLink(line, &r1, &r2))
			exit_with_not_valid_map();
		else
			addLink(lem, r1, r2);
		if (ft_strchr(line, EOF))
			break;
	}
}

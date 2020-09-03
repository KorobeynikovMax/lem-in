#ifndef LEM_IN_H# define LEM_IN_H# include <stdio.h># include <stdlib.h># include "libft.h"/***-----------------------------------Structs------------------------------------*/typedef struct				s_room_address	t_room_address;typedef struct				s_room			t_room;typedef struct				s_lem			t_lem;struct						s_room{	char					*name;	int						x_coord;	int						y_coord;	int						visitFlag;	int						start_endFlag;	t_room_address			*links;};struct						s_room_address{	t_room					*address;	struct s_room_address	*next;};struct						s_lem{	int						countAnts;	t_room					*map;};/***----------------------------------Functions-----------------------------------*/void						parseMap(t_lem *lem);/***Functions for error message*/void						exitWithNotValidMap();void						exitWithReadError();#endif
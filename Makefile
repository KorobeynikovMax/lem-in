# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bedavis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/03 16:40:31 by bedavis           #+#    #+#              #
#    Updated: 2020/08/03 17:11:01 by bedavis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = src/main.c \
		src/move_ants/move_and_print_ants.c \
        src/move_ants/move_group_ants.c \
        src/move_ants/ants_distributor.c \
        src/move_ants/put_new_ant_on_path.c \
        src/parse_functions/parse_link_rooms.c \
        src/parse_functions/parse_map.c \
        src/parse_functions/parse_rooms.c \
        src/structs_functions/indexes.c \
        src/structs_functions/paths.c \
        src/structs_functions/room_functions.c \
        src/structs_functions/room_adress_functions.c \
        src/structs_functions/room_links.c \
        src/exit_protocol.c \
        src/free_functions.c \
        src/protecred_lib_functions.c \
        src/solution.c



LIB_HEADER = $(LIB_PATH)includes/

LIB_PATH = ./libft/

OBJ		=	$(SRC:.c=.o)

%.o:%.c
			@echo " - Creating $<..."
			$(CC) $(CFLAGS) -c $< -o $@ $(INC)

CFLAGS	=	
#-Wall -Wextra -Werror -Ofast 

INC		=	-I includes -I $(LIB_HEADER)

LIB		=	-L ./libft -lft

CC		= 	gcc

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INC) $(LIB)

clean:
	@echo " - Cleaning object files..."
	@rm -f $(OBJ)

fclean: clean
	@echo " - Cleaning binary..."
	@make fclean -C libft/
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re

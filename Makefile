# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 12:01:17 by oabdelha          #+#    #+#              #
#    Updated: 2022/06/22 09:42:45 by oabdelha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CM = cc

FLAG_MLX = -Lmlx -framework OpenGL -framework AppKit

FLAG = -g -Wall -Wextra -Werror

SRC = main.c checking.c get_line.c \
		helper_fonctions.c position_p.c \
		move_player.c initialization.c \
		raycast.c utils.c map_check.c \
		init_hooks.c key_handlers.c \
		movement_handlers.c \
		load.c wall_check.c count_functions.c \
		checking2.c floor_ceilling.c checking_utils.c \
		init_utils.c checking_utils2.c draw.c build_map.c \
		mini_map_bonus.c mous_move_bonus.c

OBJECT_PATH = ./object_files/

UTILS_PATH = ./utils/

FOBJ_SRC = object_files

M_OBJECTS = $(addprefix $(OBJECT_PATH), $(SRC:.c=.o))

INCLUDE = includes/cub3d.h

CONSTANT = includes/constant.h

all: $(NAME)

$(NAME): $(FOBJ_SRC) $(M_OBJECTS) $(S_OBJECTS) $(INCLUDE) $(CONSTANT)
	@cd libft; make
	@cc $(FLAG) $(M_OBJECTS) $(S_OBJECTS) libft/libft.a $(FLAG_MLX) mlx/libmlx.a -o cub3D

$(OBJECT_PATH)%.o : %.c $(INCLUDE) $(CONSTANT)
	@$(CM) $(FLAG) -o $@  -c $<

$(OBJECT_PATH)%.o : $(UTILS_PATH)%.c $(INCLUDE) $(CONSTANT)
	@$(CM) $(FLAG) -o $@  -c $<

$(FOBJ_SRC) :
	@mkdir $@

clean:
	@cd libft; make clean
	@rm -rf $(OBJECTS)
	@rm -rf $(FOBJ_SRC)

fclean: clean
	@cd libft; make fclean
	@rm -rf $(NAME) cub3D

re: fclean all

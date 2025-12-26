# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 09:50:22 by nnomenja          #+#    #+#              #
#    Updated: 2025/12/08 09:48:41 by nnomenja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
RM = rm

# Directories
MLX_DIR = minilibx-linux/

# Library
MLX_LIB =  mlx

MLX_FLAGS = -L$(MLX_DIR) -l$(MLX_LIB)  -lXext -lX11 -lm -lz -O3
CFLAGS =  -Wall -Wextra -Werror
RMFLAGS = -rf

vpath %.c parse basic_utils inits utils event render controls mini-map hooks

SRCS = main.c



SRCS += 	read_map.c \
			get_map_data.c \
			check_map_data.c \
			check_map.c \
			check_missing.c \
			map_utils.c \
			map_utils_1.c \
			map_utils_2.c \
			map_utils_3.c \
			color_utils.c \
			path_utils.c \
			filename.c
			
SRCS += 	str_cmp.c \
			str_n_cmp.c \
			str_len.c \
			str_dup.c \
			str_cat.c \
			str_cpy.c \
			str_dup_delim.c \
			str_n_join.c \
			str_tok.c \
			check_char.c \
			print_error.c \
			exit_error.c \
			put_str.c \
			ft_atoi.c \
			ft_atol.c \
			ft_split.c \
			free_split.c \
			without_spaces.c

SRCS += 	angle.c \
			color.c \
			pixel.c \
			free.c

SRCS += 	windows.c \
			clean.c

SRCS +=		draw.c \
        	nearby_wall_horizontal.c \
			nearby_wall_vertical.c \
			ray_utils.c \
			nearby_wall.c \
			ray.c \
			render.c

SRCS += 	frame.c \

SRCS +=		collision.c \
			controls.c \
			moveHorizontal.c \
			moveVertical.c

SRCS += 	mini_map.c \
			cursor.c  \
			img_utils.c \
			map_frame.c \
			ajust_col.c

SRCS +=	 loop_hooks.c \
		key_hooks.c

OBJS = $(addprefix objs/, $(SRCS:.c=.o))

all		: $(NAME)

$(NAME)	:	$(OBJS)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS)    $^ $(MLX_FLAGS)  -Lmlx -o $@

objs/%.o : %.c
	mkdir -p objs
	$(CC) $(CFLAGS)   -c $< -o $@

clean	: bonus_clean
	
	make clean -C $(MLX_DIR)
	$(RM) $(RMFLAGS) objs

fclean	: clean bonus_fclean
	$(RM) $(RMFLAGS) $(NAME)

bonus:
	@make -C ./bonus_files

bonus_clean:
	@make clean -C ./bonus_files

bonus_fclean:
	@make fclean -C ./bonus_files

bonus_re:
	@make re -C ./bonus_files

bonus_all:
	@make all -C ./bonus_files

re		:	fclean all

.PHONY	:	all clean fclean re

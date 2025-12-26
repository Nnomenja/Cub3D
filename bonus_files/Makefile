# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 09:50:22 by nnomenja          #+#    #+#              #
#    Updated: 2025/12/08 09:49:57 by nnomenja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D_bonus

CC = cc
RM = rm

# Directories
MLX_DIR = ../minilibx-linux/

# Library
MLX_LIB =  mlx

MLX_FLAGS = -L$(MLX_DIR) -l$(MLX_LIB)  -lXext -lX11 -lm -lz -O3
CFLAGS = -Wall -Wextra -Werror
RMFLAGS = -rf

vpath %.c parse basic_utils inits utils event render controls mini-map hooks

SRCS = main_bonus.c



SRCS += 	read_map_bonus.c \
			get_map_data_bonus.c \
			check_map_data_bonus.c \
			check_map_bonus.c \
			check_missing_bonus.c \
			map_utils_bonus.c \
			map_utils_1_bonus.c \
			map_utils_2_bonus.c \
			map_utils_3_bonus.c \
			color_utils_bonus.c \
			path_utils_bonus.c \
			filename_bonus.c \
			check_gates_bonus.c
			
SRCS += 	str_cmp_bonus.c \
			str_n_cmp_bonus.c \
			str_len_bonus.c \
			str_dup_bonus.c \
			str_cat_bonus.c \
			str_cpy_bonus.c \
			str_dup_delim_bonus.c \
			str_n_join_bonus.c \
			str_tok_bonus.c \
			check_char_bonus.c \
			print_error_bonus.c \
			exit_error_bonus.c \
			put_str_bonus.c \
			ft_atoi_bonus.c \
			ft_atol_bonus.c \
			ft_split_bonus.c \
			free_split_bonus.c \
			without_spaces_bonus.c

SRCS += 	angle_bonus.c \
			color_bonus.c \
			pixel_bonus.c \
			free_bonus.c \
			images_bonus.c

SRCS += 	windows_bonus.c \
			clean_bonus.c \
			sprites_bonus.c

SRCS +=		draw_bonus.c \
        	nearby_wall_horizontal_bonus.c \
			nearby_wall_vertical_bonus.c \
			ray_utils_bonus.c \
			nearby_wall_bonus.c \
			ray_bonus.c \
			render_bonus.c

SRCS += 	frame_bonus.c \
			mouse_bonus.c

SRCS +=		collision_bonus.c \
			controls_bonus.c \
			moveHorizontal_bonus.c \
			moveVertical_bonus.c \
			gate_bonus.c \
			gate_utils_bonus.c

SRCS += 	mini_map_bonus.c \
			cursor_bonus.c  \
			img_utils_bonus.c \
			map_frame_bonus.c \
			ajust_col_bonus.c
			
SRCS +=  	mouses_bonus.c \
			loops_bonus.c \
			key_bonus.c
			
OBJS = $(addprefix objs/, $(SRCS:.c=.o))

all		: $(NAME)

$(NAME)	:	$(OBJS)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS)    $^ $(MLX_FLAGS)  -Lmlx -o $@

objs/%.o : %.c
	mkdir -p objs
	$(CC) $(CFLAGS)   -c $< -o $@

clean	:

	make clean -C $(MLX_DIR)
	$(RM) $(RMFLAGS) objs

fclean	: clean
	$(RM) $(RMFLAGS) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re

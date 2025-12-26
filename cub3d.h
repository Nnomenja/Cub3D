/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:39:37 by nnomenja          #+#    #+#             */
/*   Updated: 2025/12/06 11:51:11 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define MAP_EXTESION ".cub"
# define HEIGHT 512
# define WIDTH 1024
# define PIXEL 64
# define PI 3.141592653589793238462643383
# define FOV 60
# define RES 4
# define EMF0 "Invalid map file extension name"
# define EMF1 "Invalid map file"
# define MOVE_SPEED 4
# define ROTATE_SPEED .05f
# define SENSIVITY 10
# include "./minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

typedef struct s_point
{
	float		x;
	float		y;
}				t_point;

typedef enum s_type
{
	HT = 90,
	VT
}				t_type;

typedef enum s_side
{
	TOP = 80,
	DOWN,
	LEFT,
	RIGHT,
	BOTTOM,
	TOP_LEFT,
	TOP_RIGHT,
	BOTTOM_LEFT,
	BOTTOM_RIGHT
}				t_side;

typedef struct s_n
{
	int			t;
	int			b;
	int			l;
	int			r;
	int			tl;
	int			tr;
	int			bl;
	int			br;
}				t_n;

typedef struct s_ray
{
	int			i;
	t_point		pos;
	t_point		start;
	float		t_start;
	double		distance;
	double		angle;
	float		offset;
	t_type		type;
	float		line_length;
	int			begin;
	int			color;
	t_side		side;
}				t_ray;

typedef struct s_img
{
	int			width;
	int			height;
	void		*addr;
	char		*b_addr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct s_map_data
{
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	char		*c;
	char		*f;
	char		*map;
}				t_map_data;

typedef struct s_mini_map
{
	t_img		backups;
	t_point		p;
	double		cx;
	double		cy;
	double		px;
	double		py;
	double		cos_a;
	double		sin_a;
	t_img		cursor;
	t_img		frame;
}				t_mini_map;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	int			col;
	int			row;
	int			w;
	int			h;
	t_img		screen;
	t_point		player;

	double		angle;
	t_ray		rays[WIDTH];
	double		rotate_speed;
	double		move_speed;
	int			mouse_x;

	t_mini_map	mini_map;

	t_map_data	map_data;
	int			px;
	int			py;
	char		**map;
	t_img		no;
	t_img		so;
	t_img		we;
	t_img		ea;

	bool		move;
	int			walk_direction;
	int			turn_direction;
	int			key;
}				t_data;

#endif
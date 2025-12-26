/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:39:37 by nnomenja          #+#    #+#             */
/*   Updated: 2025/12/06 11:54:38 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

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
# define ROTATE_SPEED .01f
# define SENSIVITY 10
# define SPRITES_COUNT 5
# define SHOW_MOUSE 0
# include "../minilibx-linux/mlx.h"
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
	VT,
	HTC,
	VTC,
}			t_type;

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
	char		*g;
	char		*gw;
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
	/*------- windows -------*/
	void		*mlx;
	void		*mlx_win;
	int			col;
	int			row;
	int			w;
	int			h;
	t_img		screen;
	t_point		player;

	/*------- Controls -------*/
	double		angle;
	t_ray		rays[WIDTH];
	double		rotate_speed;
	double		move_speed;
	int			mouse_x;

	/*------- Mini-map -------*/
	t_mini_map	mini_map;

	/*------- Gate sliding -------*/
	bool		gate;
	t_point		g_p;
	int			g_status;	
	int			g_value;
	bool		g_trigger;
	bool		g_enter;

	/*------- Map data -------*/
	t_map_data	map_data;
	int			px;
	int			py;
	char		**map;
	t_img		no;
	t_img		so;
	t_img		we;
	t_img		ea;
	t_img		g;
	t_img		gw;

	/*------- Gun -------*/
	t_img		sprites[SPRITES_COUNT];
	t_img		curr_sprites;
	int			i;
	/*------- Controls -------*/
	bool		move;
	bool		move_mouse;
	bool		hide_mouse;
	int			walk_direction;
	int			turn_direction;
	int			key;
}				t_data;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 01:49:43 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/18 12:43:31 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define MN_PIXEL 30
# define MN_SIZE 200

# include "../cub3d.h"
# include "../utils/utils.h"

typedef struct s_params
{
	double	dx;
	double	dy;
	double	sx;
	double	sy;
}			t_params;

/*------- Cursor -------*/
void		init_cursor(t_data *data);
void		put_arrow_img(t_img *img, t_data *data, int x, int y);
/*------- Map utils -------*/
void		put_square(t_point p, int color, int bordered, t_data *data);
void		draw_map(char **map, t_data *data);
void		new_empty_frame(t_img *tmp, t_data *data);
/*------- Map frame -------*/
void		init_frame(t_img *frame, void *mlx);
void		make_frame_circle(t_img *frame);
void		put_map_to_frame(t_img *frame, t_img *map);
void		init_map(t_data *data);
void		render_map(t_data *data);
void		set_player(t_point p, t_point *v);
void		put_mini_map_to_window(t_img *frame, t_data *data, int pt, int pl);
/*------- Ajust col -------*/
void		ajust_col(char **map, int col);
void		fill_space(char **map);

#endif
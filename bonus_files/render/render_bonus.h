/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 04:59:27 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/25 09:34:01 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_BONUS_H
# define RENDER_BONUS_H

# include "../cub3d_bonus.h"
# include "../mini-map/map_bonus.h"
# include "../utils/utils_bonus.h"
# include "../controls/controls_bonus.h"

# define GUN_SIZE 250 

typedef struct s_rt
{
	t_point	p;
	t_type	type;
	bool	stop;
}			t_rt;

/*------- Draw -------*/
void		draw_wall(t_data *data, int index, t_img *textures);
void		draw_ceil(t_ray *ray, int color, int i, t_data *data);
void		draw_floor(t_ray *ray, int color, int i, t_data *data);
void		draw_vertical_line(t_point start, int height, t_data *data,
				int color);
t_side		ray_side(t_point p, t_type type, char **map);
t_rt		get_ray_type(t_rt h, t_rt v, t_data *data);
/*------- Ray -------*/
void		emit_rays(t_data *data);
/*------- Nearby wall -------*/
t_rt		f_vertical(t_data *data, double angle);
t_rt		f_horizontal(t_data *data, double angle);
void		get_nearby_wall(t_data *data, double angle, int i);
void		set_outside(t_point *p);
/*------- Render -------*/
void		render(t_data *data);

void		render_debug(t_data *data);

#endif
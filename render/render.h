/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 04:59:27 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/11 09:38:53 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "../cub3d.h"
# include "../utils/utils.h"
# include "../mini-map/map.h"

/*------- Draw -------*/
void	draw_wall(t_data *data, int index, t_img *textures);
void	draw_ceil(t_ray *ray, int color, int i, t_data *data);
void	draw_floor(t_ray *ray, int color, int i, t_data *data);
void	draw_vertical_line(t_point start, int height, t_data *data, int color);
t_side	ray_side(t_point p, t_type type, char **map);
t_type	get_ray_type(t_point h, t_point v, t_data *data);
/*------- Ray -------*/
void	emit_rays(t_data *data);
/*------- Nearby wall -------*/
t_point	f_vertical(t_data *data, double angle);
t_point	f_horizontal(t_data *data, double angle);
void	get_nearby_wall(t_data *data, double angle, int i);
/*------- Render -------*/
void	render(t_data *data);

#endif
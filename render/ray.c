/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 05:00:50 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/11 10:16:55 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render.h"

static t_img	*get_texture(t_side type, t_data *data)
{
	if (type == TOP)
		return (&data->no);
	if (type == BOTTOM)
		return (&data->so);
	if (type == RIGHT)
		return (&data->ea);
	return (&data->we);
}

static void	set_offset(t_ray *ray, t_img *txt)
{
	if (ray->type == VT)
		ray->offset = (((int)ray->pos.y % PIXEL) * txt->width) / PIXEL;
	else
		ray->offset = (((int)(ray->pos.x) % PIXEL) * txt->height) / PIXEL;
}

static double	ajusted_distance(t_point p, t_point end, double p_angle,
		double r_angle)
{
	double	value;

	value = distance(p, end);
	if (r_angle > p_angle)
		value *= cos(r_angle - p_angle);
	else
		value *= cos(p_angle - r_angle);
	return (value);
}

static void	set_entities(t_ray *ray, t_img *txt, int i)
{
	set_offset(ray, txt);
	ray->line_length = (PIXEL / ray->distance) * (512 / tan(deg_to_rad(FOV)
				/ 2));
	ray->begin = (HEIGHT / 2) - (ray->line_length / 2);
	ray->start.x = i;
	ray->start.y = ray->begin;
	ray->t_start = 0.0;
	if (ray->line_length >= HEIGHT)
	{
		ray->start.y = 0;
		ray->t_start = (((ray->line_length - HEIGHT) * txt->height) / (2
					* ray->line_length));
	}
}

void	emit_rays(t_data *data)
{
	double	deg;
	int		i;
	t_img	*txt;

	deg = data->angle - (deg_to_rad(FOV) / 2);
	i = -1;
	while (++i < WIDTH)
	{
		get_nearby_wall(data, normalize_angle(deg), i);
		txt = get_texture(data->rays[i].side, data);
		data->rays[i].distance = ajusted_distance(data->player,
				data->rays[i].pos, data->angle, deg);
		set_entities(&(data->rays[i]), txt, i);
		draw_ceil(&data->rays[i], get_color(data->map_data.c), i, data);
		draw_wall(data, i, txt);
		draw_floor(&data->rays[i], get_color(data->map_data.f), i, data);
		deg += (double)(deg_to_rad(FOV) / WIDTH);
		(void)txt;
	}
}

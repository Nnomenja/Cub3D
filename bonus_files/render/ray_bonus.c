/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 05:00:50 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/24 13:54:29 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render_bonus.h"

static t_img	*get_texture(t_side side, t_data *data, t_type type, t_point p)
{
	if (type == HTC || type == VTC)
	{
		if (gate_orientation(p, data->map, type))
			return (&data->g);
		else
			return (&data->gw);
	}
	if (side == TOP)
		return (&data->no);
	if (side == BOTTOM)
		return (&data->so);
	if (side == RIGHT)
		return (&data->ea);
	return (&data->we);
}

static void	set_offset(t_ray *ray, t_img *txt, t_data *data)
{
	int		value;
	int		skip;
	char	**map;
	t_point	p;

	skip = data->g_value;
	map = data->map;
	p = ray->pos;
	if (ray->type == VT || (ray->type == VTC && \
	(!gate_orientation(p, map, VTC) || !current_gates(p, VTC, data))))
		value = (((int)ray->pos.y % PIXEL) * txt->width) / PIXEL;
	else if (ray->type == HT || (ray->type == HTC && \
	(!gate_orientation(p, map, HTC) || !current_gates(p, HTC, data))))
		value = (((int)(ray->pos.x) % PIXEL) * txt->height) / PIXEL;
	else if (ray->type == VTC || gate_orientation(p, map, VTC))
		value = ((((int)ray->pos.y - skip) % PIXEL) * txt->width) / PIXEL;
	else
		value = ((((int)(ray->pos.x) + skip) % PIXEL) * txt->height) / PIXEL;
	(void)skip;
	ray->offset = value;
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

static void	set_entities(t_ray *ray, t_img *txt, int i, t_data *data)
{
	set_offset(ray, txt, data);
	ray->line_length = (PIXEL / ray->distance) * (512 / tan(deg_to_rad(FOV)
				/ 2));
	ray->begin = (HEIGHT / 2) - (ray->line_length / 2);
	ray->start.x = i;
	ray->start.y = ray->begin;
	ray->t_start = 0.0;
	if (ray->line_length >= HEIGHT)
	{
		ray->start.y = 0;
		ray->t_start = (((ray->line_length - HEIGHT) * txt->height) / (2 \
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
		txt = get_texture(data->rays[i].side, data, \
		data->rays[i].type, data->rays[i].pos);
		data->rays[i].distance = ajusted_distance(data->player, \
		data->rays[i].pos, data->angle, deg);
		set_entities(&(data->rays[i]), txt, i, data);
		draw_ceil(&data->rays[i], get_color(data->map_data.c), i, data);
		draw_wall(data, i, txt);
		draw_floor(&data->rays[i], get_color(data->map_data.f), i, data);
		deg += (double)(deg_to_rad(FOV) / WIDTH);
		(void)txt;
	}
}

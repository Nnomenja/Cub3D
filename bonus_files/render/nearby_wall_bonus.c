/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearby_wall_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 05:45:56 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/25 09:30:51 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render_bonus.h"

void	set_outside(t_point *p)
{
	p->x = -1;
	p->y = -1;
}

void	get_nearby_wall(t_data *data, double angle, int i)
{
	t_rt	h;
	t_rt	v;
	t_rt	ray;

	data->rays[i].i = i;
	h = f_horizontal(data, angle);
	v = f_vertical(data, angle);
	ray = get_ray_type(h, v, data);
	data->rays[i].type = ray.type;
	data->rays[i].pos = ray.p;
	if (ray.type == VT)
	{
		data->rays[i].color = rgb(8, 244, 165);
	}
	else if (ray.type == HT)
	{
		data->rays[i].color = rgb(0, 85, 57);
	}
	else if (ray.type == HTC)
		data->rays[i].color = rgb(179, 0, 255);
	else
		data->rays[i].color = rgb(255, 0, 64);
	data->rays[i].side = ray_side(data->rays[i].pos, ray.type, data->map);
}

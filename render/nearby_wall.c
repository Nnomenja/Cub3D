/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearby_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 05:45:56 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/08 10:10:12 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render.h"

void	get_nearby_wall(t_data *data, double angle, int i)
{
	t_point	h;
	t_point	v;
	t_type	type;

	data->rays[i].i = i;
	h = f_horizontal(data, angle);
	v = f_vertical(data, angle);
	type = get_ray_type(h, v, data);
	if (type == VT)
	{
		data->rays[i].color = rgb(8, 244, 165);
		data->rays[i].type = VT;
		data->rays[i].pos = v;
	}
	else
	{
		data->rays[i].color = rgb(0, 85, 57);
		data->rays[i].type = HT;
		data->rays[i].pos = h;
	}
	data->rays[i].side = ray_side(data->rays[i].pos, type, data->map);
}

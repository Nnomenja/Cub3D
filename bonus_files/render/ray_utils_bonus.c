/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 05:11:45 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/24 13:54:29 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render_bonus.h"
#include "../controls/controls_bonus.h"

t_rt	get_ray_type(t_rt h, t_rt v, t_data *data)
{
	t_rt	res;

	if (h.p.x < 0.0 || h.p.y < 0.0)
		res = v;
	else if (v.p.x < 0.0 || v.p.y < 0.0)
		res = h;
	else if (distance(data->player, v.p) < distance(data->player, h.p))
		res = v;
	else
		res = h;
	return (res);
}

t_side	ray_side(t_point p, t_type type, char **map)
{
	if (type == HT || type == HTC)
	{
		if (is_block(map[((int)p.y / 64) - 1][(int)p.x / 64]))
			return (TOP);
		return (BOTTOM);
	}
	else
	{
		if (is_block(map[((int)p.y / 64)][((int)p.x / 64) - 1]))
			return (LEFT);
		return (RIGHT);
	}
}

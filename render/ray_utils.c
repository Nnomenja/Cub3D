/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 05:11:45 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/08 10:12:41 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render.h"

t_type	get_ray_type(t_point h, t_point v, t_data *data)
{
	t_type	res;

	if (h.x < 0.0 || h.y < 0.0)
		res = VT;
	else if (v.x < 0.0 || v.y < 0.0)
		res = HT;
	else if (distance(data->player, v) < distance(data->player, h))
		res = VT;
	else
		res = HT;
	return (res);
}

t_side	ray_side(t_point p, t_type type, char **map)
{
	if (type == HT)
	{
		if (map[((int)p.y / 64) - 1][(int)p.x / 64] == '1')
			return (TOP);
		return (BOTTOM);
	}
	else
	{
		if (map[((int)p.y / 64)][((int)p.x / 64) - 1] == '1')
			return (LEFT);
		return (RIGHT);
	}
}

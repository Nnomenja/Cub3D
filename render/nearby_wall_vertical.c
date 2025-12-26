/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearby_wall_vertical.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 05:52:20 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/08 10:13:44 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render.h"

static t_side	v_looking(double radAngle)
{
	if (rad_to_deg(radAngle) >= 270 || rad_to_deg(radAngle) <= 90)
		return (RIGHT);
	return (LEFT);
}

static t_point	vertical(t_point p, double angle, char **map, t_data *data)
{
	int	row;
	int	col;

	if (p.x < 0 || p.y < 0)
		return (p);
	if (v_looking(angle) == LEFT)
		col = pixel_position(p, data).x - 1;
	else
		col = pixel_position(p, data).x;
	row = pixel_position(p, data).y;
	if (p.x >= data->w || p.y >= data->h)
		return ((t_point){-1, -1});
	if (map[row][col] == '1')
		return (p);
	if (v_looking(angle) == LEFT)
	{
		p.x -= PIXEL;
		p.y += (PIXEL * -1) * tan(angle);
	}
	else
	{
		p.x += PIXEL;
		p.y += PIXEL * tan(angle);
	}
	return (vertical(p, angle, map, data));
}

t_point	f_vertical(t_data *data, double angle)
{
	t_point	start;
	t_point	p;
	t_point	last;

	p = data->player;
	start.x = floor((data->player.x * data->col) / data->w);
	if (v_looking(angle) == RIGHT)
		start.x += 1;
	start.x *= PIXEL;
	start.y = (((start.x - p.x) * tan(angle)) + p.y);
	if (start.x >= data->w || start.y >= data->h || start.x < 0 || start.y < 0)
		return ((t_point){-1, -1});
	last = vertical(start, angle, data->map, data);
	if (last.x > 0 && last.y > 0)
		return (last);
	return ((t_point){-1, -1});
}

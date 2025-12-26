/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearby_wall_horizontal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 05:53:54 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/08 10:12:30 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render.h"

static t_side	h_looking(double radAngle)
{
	if (rad_to_deg(radAngle) <= 180)
		return (DOWN);
	return (TOP);
}

static t_point	horizontal(t_point p, double angle, char **map, t_data *data)
{
	int	row;
	int	col;

	if (p.x < 0 || p.y < 0)
		return (p);
	if (h_looking(angle) == TOP)
		row = pixel_position(p, data).y - 1;
	else
		row = pixel_position(p, data).y;
	col = pixel_position(p, data).x;
	if (p.x >= data->w || p.y >= data->h)
		return ((t_point){-1, -1});
	if (map[row][col] == '1')
		return (p);
	if (h_looking(angle) == TOP)
	{
		p.y -= PIXEL;
		p.x += ((PIXEL * -1) / tan(angle));
	}
	else
	{
		p.y += PIXEL;
		p.x += ((PIXEL) / tan(angle));
	}
	return (horizontal(p, angle, map, data));
}

t_point	f_horizontal(t_data *data, double angle)
{
	t_point	start;
	t_point	p;
	t_point	last;

	p = data->player;
	start.y = floor((data->player.y * data->row) / data->h);
	if (h_looking(angle) == DOWN)
		start.y += 1;
	start.y *= PIXEL;
	start.x = ((start.y - p.y) / tan(angle) + p.x);
	if (start.x >= data->w || start.y >= data->h || start.x < 0 || start.y < 0)
		return ((t_point){-1, -1});
	last = horizontal(start, angle, data->map, data);
	if (last.x >= 0 && last.y >= 0)
		return (last);
	return ((t_point){-1, -1});
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearby_wall_horizontal_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 05:53:54 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/24 13:54:29 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render_bonus.h"

static t_side	h_looking(double radAngle)
{
	if (rad_to_deg(radAngle) <= 180)
		return (DOWN);
	return (TOP);
}

static void	set_next_step(double angle, t_point *p, int step)
{
	if (h_looking(angle) == TOP)
	{
		p->y -= step;
		p->x += ((step * -1) / tan(angle));
	}
	else
	{
		p->y += step;
		p->x += ((step) / tan(angle));
	}
}

static t_rt	get_value(double angle, t_point grid, t_point p, t_data *data)
{
	int		row;
	int		col;
	char	**map;

	row = (int)grid.x;
	col = (int)grid.y;
	map = data->map;
	if (map[row][col] == '1')
	{
		if (h_looking(angle) == TOP && map[row + 1][col] == 'C')
			return ((t_rt){p, HTC, true});
		if (h_looking(angle) == DOWN && map[row - 1][col] == 'C')
			return ((t_rt){p, HTC, true});
		if (h_looking(angle) == TOP && map[row + 1][col] == 'O')
			return ((t_rt){p, HTC, true});
		if (h_looking(angle) == DOWN && map[row - 1][col] == 'O')
			return ((t_rt){p, HTC, true});
		return ((t_rt){p, HT, true});
	}
	set_next_step(angle, &p, PIXEL / 2);
	if ((data->g_p.x && p.x < ((data->g_p.x * PIXEL) + \
	(PIXEL - data->g_value))) && current_gates(p, HTC, data))
		return ((t_rt){p, HTC, false});
	(void)data;
	return ((t_rt){p, HTC, true});
}

static	t_rt	horizontal(t_point p, double angle, t_data *data, t_type t)
{
	int		row;
	int		col;
	t_rt	tmp;
	char	**map;

	map = data->map;
	if (p.x < 0 || p.y < 0)
		return ((t_rt){p, t, true});
	if (h_looking(angle) == TOP)
		row = pixel_position(p, data).y - 1;
	else
		row = pixel_position(p, data).y;
	col = pixel_position(p, data).x;
	if (p.x >= data->w || p.y >= data->h)
		return ((t_rt){(t_point){-1, -1}, HT, true});
	if (map[row][col] == '1' || map[row][col] == 'C' || map[row][col] == 'O')
	{
		tmp = get_value(angle, (t_point){row, col}, p, data);
		if (tmp.stop)
			return (tmp);
		t = tmp.type;
	}
	set_next_step(angle, &p, PIXEL);
	return (horizontal(p, angle, data, t));
}

t_rt	f_horizontal(t_data *data, double angle)
{
	t_point	start;
	t_point	p;
	t_rt	last;

	p = data->player;
	start.y = floor((data->player.y * data->row) / data->h);
	if (h_looking(angle) == DOWN)
		start.y += 1;
	start.y *= PIXEL;
	start.x = ((start.y - p.y) / tan(angle) + p.x);
	if (start.x >= data->w || start.y >= data->h || start.x < 0 || start.y < 0)
		return (set_outside(&last.p), last);
	last = horizontal(start, angle, data, HT);
	if (last.p.x >= 0 && last.p.y >= 0)
		return (last);
	return ((set_outside(&last.p), last));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearby_wall_vertical_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 05:52:20 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/24 13:54:29 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render_bonus.h"

static t_side	v_looking(double radAngle)
{
	if (rad_to_deg(radAngle) >= 270 || rad_to_deg(radAngle) <= 90)
		return (RIGHT);
	return (LEFT);
}

static void	set_next_step(double angle, t_point *p, int step)
{
	if (v_looking(angle) == LEFT)
	{
		p->x -= step;
		p->y += (step * -1) * tan(angle);
	}
	else
	{
		p->x += step;
		p->y += step * tan(angle);
	}
}

static t_rt	get_value(double angle, t_point grid, t_point p, t_data *data)
{
	int		row;
	int		col;
	char	**map;

	map = data->map;
	row = (int)grid.x;
	col = (int)grid.y;
	if (map[row][col] == '1')
	{
		if (v_looking(angle) == LEFT && map[row][col + 1] == 'C')
			return ((t_rt){p, VTC, true});
		if (v_looking(angle) == RIGHT && map[row][col - 1] == 'C')
			return ((t_rt){p, VTC, true});
		if (v_looking(angle) == LEFT && map[row][col + 1] == 'O')
			return ((t_rt){p, VTC, true});
		if (v_looking(angle) == RIGHT && map[row][col - 1] == 'O')
			return ((t_rt){p, VTC, true});
		return ((t_rt){p, VT, true});
	}
	set_next_step(angle, &p, PIXEL / 2);
	if (data->g_p.y >= 0 && (p.y) > ((data->g_p.y * PIXEL) + \
	(data->g_value)) && current_gates(p, VTC, data))
		return ((t_rt){p, VT, false});
	return ((t_rt){p, VTC, true});
}

static t_rt	vertical(t_point p, double angle, t_data *data, t_type t)
{
	int		row;
	int		col;
	t_rt	tmp;
	char	**map;

	map = data->map;
	if (p.x < 0 || p.y < 0)
		return ((t_rt){p, t, true});
	if (v_looking(angle) == LEFT)
		col = pixel_position(p, data).x - 1;
	else
		col = pixel_position(p, data).x;
	row = pixel_position(p, data).y;
	if (p.x >= data->w || p.y >= data->h)
		return ((t_rt){(t_point){-1, -1}, VT, true});
	if (map[row][col] == '1' || map[row][col] == 'C' || map[row][col] == 'O')
	{
		tmp = get_value(angle, (t_point){row, col}, p, data);
		if (tmp.stop)
			return (tmp);
		t = tmp.type;
	}
	set_next_step(angle, &p, PIXEL);
	return (vertical(p, angle, data, t));
}

t_rt	f_vertical(t_data *data, double angle)
{
	t_point	start;
	t_point	p;
	t_rt	last;

	p = data->player;
	start.x = floor((data->player.x * data->col) / data->w);
	if (v_looking(angle) == RIGHT)
		start.x += 1;
	start.x *= PIXEL;
	start.y = (((start.x - p.x) * tan(angle)) + p.y);
	if (start.x >= data->w || start.y >= data->h || start.x < 0 || start.y < 0)
		return (set_outside(&last.p), last);
	last = vertical(start, angle, data, VT);
	if (last.p.x > 0 && last.p.y > 0)
		return (last);
	return (set_outside(&last.p), last);
}

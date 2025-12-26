/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gate_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:08:15 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/24 13:54:29 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./controls_bonus.h"

void	in_front_of_gate(t_data *data)
{
	double	angle;
	int		row;
	int		col;

	angle = data->angle;
	row = data->player.y / PIXEL;
	col = data->player.x / PIXEL;
	if (comprise(angle, 45, 135))
		row++;
	else if (comprise(angle, 135, 225))
		col--;
	else if (comprise(angle, 225, 315))
		row--;
	else
		col++;
	if ((data->map[row][col] == 'C' || data->map[row][col] == 'O') \
	&& !data->g_enter)
	{
		data->g_p.x = col;
		data->g_p.y = row;
		data->gate = true;
	}
	else
		data->gate = false;
}

void	on_enter_gate(char **map, t_point p, t_data *data)
{
	p = pixel_position(p, data);
	if (map[(int)p.y][(int)p.x] == 'O')
		data->g_enter = true;
}

bool	current_gates(t_point end, t_type t, t_data *data)
{
	if (t == VTC)
		return (data->g_p.x == (int)end.x / PIXEL);
	return (data->g_p.y == (int)end.y / PIXEL);
}

bool	gate_orientation(t_point p, char **map, t_type type)
{
	int		x;
	int		y;
	char	curr;

	x = (int)p.x;
	y = (int)p.y;
	curr = map[(y / PIXEL)][(x / PIXEL)];
	if (type == HTC)
	{
		if (map[y / PIXEL][(x / PIXEL) - 1] == '1' && \
		map[y / PIXEL][(x / PIXEL) + 1] == '1' && \
		(curr == 'C' || curr == 'O'))
			return (true);
		return (false);
	}
	else
	{
		if (map[(y / PIXEL) - 1][(x / PIXEL)] == '1' && \
		map[(y / PIXEL) + 1][(x / PIXEL)] == '1' && \
		(curr == 'C' || curr == 'O'))
			return (true);
		return (false);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gate_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:54:42 by nnomenja          #+#    #+#             */
/*   Updated: 2025/12/06 11:33:32 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./controls_bonus.h"

void	handle_the_gate(t_data *data)
{
	in_front_of_gate(data);
	data->g_trigger = true;
	if (!data->gate)
		return ;
	if (data->g_status == CLOSE)
		data->g_status = OPEN;
	else
		data->g_status = CLOSE;
}

void	auto_hide_gate(t_data *data)
{
	char	**map;
	t_point	p;

	map = data->map;
	p = pixel_position(data->player, data);
	if ((data->g_value < PIXEL && !data->gate && \
	map[(int)p.y][(int)p.x] != 'O') || (data->g_enter \
	&& map[(int)p.y][(int)p.x] != 'O'))
	{
		data->g_trigger = true;
		data->gate = true;
		data->g_status = CLOSE;
	}
}

static void	on_gate_opened(t_data *data)
{
	data->g_value = PIXEL - 1;
	data->g_trigger = false;
	data->map[(int)data->g_p.y][(int)data->g_p.x] = 'C';
	data->g_enter = false;
	data->g_p = (t_point){-1, -1};
}

static void	on_gate_closed(t_data *data)
{
	data->g_value = 0;
	data->g_trigger = false;
	data->map[(int)data->g_p.y][(int)data->g_p.x] = 'O';
}

int	handle_gate_loop(void *params)
{
	t_data	*data;
	t_point	p;
	int		tmp;

	data = (t_data *)params;
	p = data->g_p;
	if ((p.x > 0 || p.y > 0) && data->g_trigger && data->gate)
	{
		tmp = (data->g_status * GATE_SPEED) + data->g_value;
		if (tmp >= PIXEL)
			on_gate_opened(data);
		else if (data->g_value < 0)
			on_gate_closed(data);
		else
			data->g_value = tmp;
		if (!data->move)
			render(data);
	}
	return (1);
}

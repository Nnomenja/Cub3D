/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 09:45:45 by nnomenja          #+#    #+#             */
/*   Updated: 2025/12/06 11:34:02 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hooks_bonus.h"

static int	handle_sprites_loop(void *param)
{
	t_data	*data;
	double	move_step;

	data = (t_data *)param;
	if (data->i != 0)
	{
		data->i -= 1;
		data->move = false;
		data->curr_sprites = data->sprites[data->i];
		render(data);
	}
	if (data->move || data->move_mouse)
	{
		move_step = data->walk_direction * MOVE_SPEED;
		if (data->move_mouse)
			data->angle += data->turn_direction * ROTATE_SPEED;
		else
			data->angle += data->turn_direction * (ROTATE_SPEED * 5);
		data->angle = normalize_angle(data->angle);
		move_horizontal(data->key, data->angle, data);
		move_vertical(data->walk_direction, data, move_step);
		render(data);
		mouse_release(data);
	}
	return (1);
}

int	main_loop(void *param)
{
	handle_gate_loop(param);
	handle_sprites_loop(param);
	return (1);
}

void	loop_hooks(t_data *data)
{
	mlx_loop_hook(data->mlx, main_loop, data);
	mlx_loop(data->mlx);
}

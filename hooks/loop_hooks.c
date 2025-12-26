/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:29:39 by nnomenja          #+#    #+#             */
/*   Updated: 2025/12/06 11:29:01 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hooks.h"

static int	loop(void *param)
{
	t_data	*data;
	double	move_step;

	data = param;
	if (data->move)
	{
		move_step = data->walk_direction * MOVE_SPEED;
		data->angle += data->turn_direction * ROTATE_SPEED;
		data->angle = normalize_angle(data->angle);
		move_horizontal(data->key, data->angle, data);
		move_vertical(data->walk_direction, data, move_step);
		render(data);
	}
	return (1);
}

void	loop_hooks(t_data *data)
{
	mlx_loop_hook(data->mlx, loop, data);
	mlx_loop(data->mlx);
}

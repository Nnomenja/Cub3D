/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:50:45 by nnomenja          #+#    #+#             */
/*   Updated: 2025/12/06 11:25:30 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./controls_bonus.h"

static void	handle_direction(int keycode, int *walk_direction,
		int *turn_direction)
{
	*walk_direction = 0;
	*turn_direction = 0;
	if (keycode == XK_w)
		*walk_direction = 1;
	else if (keycode == XK_s)
		*walk_direction = -1;
	else if (keycode == XK_Left)
		*turn_direction = -1;
	else if (keycode == XK_Right)
		*turn_direction = 1;
}

int	move_player(int keycode, void *param)
{
	t_data	*data;
	int		walk_direction;
	int		turn_direction;

	data = (t_data *)param;
	in_front_of_gate(data);
	on_enter_gate(data->map, data->player, data);
	if (keycode == 65307)
		close_window(data);
	else if (keycode == XK_m)
		data->hide_mouse = !data->hide_mouse;
	else if (keycode == XK_space)
		handle_the_gate(data);
	auto_hide_gate(data);
	handle_direction(keycode, &walk_direction, &turn_direction);
	if (keycode == XK_w || keycode == XK_s || keycode == XK_Left \
	|| keycode == XK_Right || keycode == XK_a || keycode == XK_d)
	{
		data->key = keycode;
		data->move = true;
	}
	data->turn_direction = turn_direction;
	data->walk_direction = walk_direction;
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:41:40 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/24 13:54:29 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./event_bonus.h"

int	mouse_leave(void *params)
{
	t_data	*data;

	data = (t_data *)params;
	if (!data->hide_mouse)
		mlx_mouse_move(data->mlx, data->mlx_win, WIDTH / 2, HEIGHT / 2);
	return (1);
}

int	mouse_move(int x, int y, void *params)
{
	t_data	*data;
	int		sub;

	data = (t_data *)params;
	if (data->hide_mouse)
		return (1);
	sub = abs(data->mouse_x - x);
	if (x == 0 || x == HEIGHT - 1)
		mlx_mouse_move(data->mlx, data->mlx_win, WIDTH / 2, HEIGHT / 2);
	if (sub < (15 + ((SENSIVITY * 15) / 100)))
		return (1);
	if (data->mouse_x > x)
		move_player(XK_Left, data);
	else
		move_player(XK_Right, data);
	data->mouse_x = x;
	data->move_mouse = true;
	(void)y;
	return (1);
}

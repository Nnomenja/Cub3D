/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouses_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 09:45:23 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/24 13:54:29 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hooks_bonus.h"

void	mouse_release(t_data *data)
{
	if (data->move_mouse)
	{
		data->move_mouse = false;
		data->move = false;
	}
}

int	mouse_down(int button, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (button == 1)
		data->i = 5;
	(void)x;
	(void)y;
	(void)param;
	(void)button;
	return (1);
}

void	mouse_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 1L << 0, move_player, data);
	mlx_hook(data->mlx_win, 8, 1L << 5, mouse_leave, data);
	mlx_hook(data->mlx_win, 6, 1L << 6, mouse_move, data);
	mlx_hook(data->mlx_win, 4, 1L << 2, mouse_down, data);
}

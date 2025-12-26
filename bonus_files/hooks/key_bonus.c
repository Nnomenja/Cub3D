/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:19:15 by nnomenja          #+#    #+#             */
/*   Updated: 2025/12/06 11:03:33 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hooks_bonus.h"

static int	key_release(int k, void *param)
{
	t_data	*data;

	data = param;
	if ((k == XK_w || k == XK_s || k == XK_Left \
	|| k == XK_Right || k == XK_a || k == XK_d) \
	&& data->move)
	{
		data->move = false;
	}
	return (1);
}

void	key_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 1L << 0, move_player, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, key_release, data);
	mlx_hook(data->mlx_win, 8, 1L << 5, mouse_leave, data);
	mlx_hook(data->mlx_win, 6, 1L << 6, mouse_move, data);
}

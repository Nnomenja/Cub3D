/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:26:32 by nnomenja          #+#    #+#             */
/*   Updated: 2025/12/06 10:52:08 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hooks.h"

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
	mlx_hook(data->mlx_win, 17, 0, close_window, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, move_player, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, key_release, data);
}

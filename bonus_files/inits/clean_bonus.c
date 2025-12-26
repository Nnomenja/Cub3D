/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:05:52 by nnomenja          #+#    #+#             */
/*   Updated: 2025/12/01 00:05:44 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./init_bonus.h"

void	cleanup_texture(t_data *data)
{
	if (data->no.addr)
		mlx_destroy_image(data->mlx, data->no.addr);
	if (data->so.addr)
		mlx_destroy_image(data->mlx, data->so.addr);
	if (data->ea.addr)
		mlx_destroy_image(data->mlx, data->ea.addr);
	if (data->we.addr)
		mlx_destroy_image(data->mlx, data->we.addr);
	if (data->g.addr)
		mlx_destroy_image(data->mlx, data->g.addr);
	if (data->gw.addr)
		mlx_destroy_image(data->mlx, data->gw.addr);
}

void	clean_sprites(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		if (data->sprites[i].addr)
			mlx_destroy_image(data->mlx, data->sprites[i].addr);
	}
}

void	cleanup_all(t_map_data map_data, t_data *data)
{
	free_map_data(&(map_data));
	cleanup_texture(data);
	clean_sprites(data);
	if (data->screen.addr)
		mlx_destroy_image(data->mlx, data->screen.addr);
	if (data->mini_map.cursor.addr)
		mlx_destroy_image(data->mlx, data->mini_map.cursor.addr);
	if (data->mini_map.frame.addr)
		mlx_destroy_image(data->mlx, data->mini_map.frame.addr);
	if (data->mini_map.backups.addr)
		mlx_destroy_image(data->mlx, data->mini_map.backups.addr);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

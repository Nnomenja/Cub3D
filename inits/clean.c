/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:05:52 by nnomenja          #+#    #+#             */
/*   Updated: 2025/12/01 00:05:16 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./init.h"

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
}

void	cleanup_all(t_map_data map_data, t_data *data)
{
	free_map_data(&(map_data));
	cleanup_texture(data);
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

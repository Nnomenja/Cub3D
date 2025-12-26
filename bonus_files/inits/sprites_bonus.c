/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 21:19:45 by nnomenja          #+#    #+#             */
/*   Updated: 2025/12/01 00:05:53 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./init_bonus.h"

static void	nullify(t_data *data)
{
	int	i;

	i = -1;
	while (++i < SPRITES_COUNT)
		data->sprites[i].addr = NULL;
}

bool	init_sprites(t_data *data, char *pathname)
{
	t_is	is;

	is.n = '0';
	is.i = -1;
	is.len = str_len(pathname);
	is.dup_path = str_dup(pathname);
	nullify(data);
	is.i = -1;
	while (++is.i < SPRITES_COUNT)
	{
		is.tmp = &data->sprites[is.i];
		is.dup_path[is.len - 5] = is.n;
		is.tmp->addr = mlx_xpm_file_to_image(data->mlx, is.dup_path, \
		&is.tmp->width, &is.tmp->height);
		if (!is.tmp->addr)
			return (free(is.dup_path), 0);
		is.n++;
		is.tmp->b_addr = mlx_get_data_addr(is.tmp->addr, &is.tmp->bpp, \
		&is.tmp->size_line, &is.tmp->endian);
	}
	assign_img(data->sprites[0], &data->curr_sprites);
	data->i = 0;
	return (free(is.dup_path), 1);
}

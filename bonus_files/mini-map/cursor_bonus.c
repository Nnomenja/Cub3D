/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:23:19 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/24 13:54:29 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./map_bonus.h"

void	init_cursor(t_data *data)
{
	t_img	*cursor;

	cursor = &data->mini_map.cursor;
	cursor->addr = mlx_xpm_file_to_image(data->mlx, "./textures/player.xpm",
			&cursor->width, &cursor->height);
	cursor->b_addr = mlx_get_data_addr(cursor->addr, &cursor->bpp,
			&cursor->size_line, &cursor->endian);
}

void	put_arrow_img(t_img *img, t_data *data, int x, int y)
{
	int	j;
	int	i;
	int	color;
	int	tmp;

	tmp = x;
	j = 0;
	while (j < img->height)
	{
		i = 0;
		x = tmp;
		while (i < img->width)
		{
			color = (unsigned int)get_pixel_color(img, (t_point){i, j}, 0);
			if (color != rgb(0, 0, 0))
				put_pixel(&data->mini_map.frame, x, y, color);
			i++;
			x++;
		}
		j++;
		y++;
	}
}

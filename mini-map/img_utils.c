/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:06:04 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/18 12:03:22 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./map.h"

void	put_square(t_point p, int color, int bordered, t_data *data)
{
	t_point	max;
	int		j;
	int		i;

	p.x *= MN_PIXEL;
	p.y *= MN_PIXEL;
	max.x = p.x;
	max.y = p.y;
	i = max.x - 1;
	while (++i < (p.x + MN_PIXEL))
	{
		j = max.y - 1;
		while (++j < (p.y + MN_PIXEL))
		{
			if (bordered)
			{
				if (i != ((p.x + MN_PIXEL) - 1) && j != (p.y + MN_PIXEL) - 1)
					put_pixel(&data->mini_map.backups, i, j, color);
				else
					put_pixel(&data->mini_map.backups, i, j, rgb(0, 0, 0));
			}
			else
				put_pixel(&data->mini_map.backups, i, j, color);
		}
	}
}

void	draw_map(char **map, t_data *data)
{
	int	j;
	int	i;
	int	len;

	j = -1;
	while (++j < data->row)
	{
		i = -1;
		len = str_len(map[j]);
		while (++i < len)
		{
			if (map[j][i] == '1')
				put_square((t_point){i, j}, rgb(40, 40, 40), 1, data);
			else if (map[j][i] == ' ')
				put_square((t_point){i, j}, rgb(12, 238, 238), 0, data);
			else
				put_square((t_point){i, j}, rgb(255, 255, 255), 1, data);
		}
	}
}

void	new_empty_frame(t_img *tmp, t_data *data)
{
	t_img	*frame;

	frame = &data->mini_map.frame;
	tmp->addr = mlx_new_image(data->mlx, frame->width, frame->height);
	tmp->b_addr = mlx_get_data_addr(tmp->addr, &tmp->bpp, &tmp->size_line,
			&tmp->endian);
	tmp->width = frame->width;
	tmp->height = frame->height;
}

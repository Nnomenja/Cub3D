/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:14:41 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/14 07:40:53 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./map.h"

bool	inside_map(int x, int y, t_img *frame)
{
	double	d;
	int		cx;
	int		cy;

	cx = frame->width / 2;
	cy = frame->height / 2;
	d = pow(x - cx, 2) + pow(y - cy, 2);
	return (d < pow(MN_SIZE / 2, 2));
}

void	make_frame_circle(t_img *frame)
{
	int	j;
	int	i;

	j = -1;
	while (++j < frame->height)
	{
		i = -1;
		while (++i < frame->width)
		{
			if (!inside_map(i, j, frame))
				put_pixel(frame, i, j, rgb(255, 0, 0));
		}
	}
}

void	init_frame(t_img *frame, void *mlx)
{
	frame->width = MN_SIZE + 10;
	frame->height = MN_SIZE + 10;
	frame->addr = mlx_new_image(mlx, frame->width, frame->height);
	frame->b_addr = mlx_get_data_addr(frame->addr, &frame->bpp,
			&frame->size_line, &frame->endian);
}

void	put_map_to_frame(t_img *frame, t_img *map)
{
	int	j;
	int	i;
	int	color;

	j = -1;
	while (++j < frame->height)
	{
		i = -1;
		while (++i < frame->width)
		{
			color = get_pixel_color(map, (t_point){i, j}, 0);
			if (color != -1)
				put_pixel(frame, i, j, color);
		}
	}
}

void	set_player(t_point p, t_point *v)
{
	v->x = (p.x * MN_PIXEL) / PIXEL;
	v->y = (p.y * MN_PIXEL) / PIXEL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 04:55:59 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/13 21:51:24 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render.h"

void	put_mini_map_to_window(t_img *frame, t_data *data, int pt, int pl)
{
	int	j;
	int	i;
	int	color;

	j = -1;
	make_frame_circle(frame);
	while (++j < frame->height)
	{
		i = -1;
		while (++i < frame->width)
		{
			color = get_pixel_color(frame, (t_point){i, j}, 0);
			if (color != rgb(255, 0, 0))
				put_pixel(&data->screen, i + pl, pt + j, color);
		}
	}
}

void	render(t_data *data)
{
	t_img	mini_map;
	t_img	*map_frame;
	int		cx;
	int		cy;

	mini_map = data->mini_map.cursor;
	map_frame = &data->mini_map.frame;
	cx = (data->mini_map.frame.width / 2) - 16;
	cy = (data->mini_map.frame.height / 2) - 16;
	emit_rays(data);
	render_map(data);
	put_arrow_img(&mini_map, data, cx, cy);
	put_mini_map_to_window(map_frame, data, (HEIGHT - 5) - map_frame->height,
		5);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->screen.addr, 0, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 04:55:59 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/24 13:54:29 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render_bonus.h"

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

void	put_gun_to_window(t_data *data, t_img v, int cx, int cy)
{
	int			i;
	int			j;
	t_point		step;
	t_point		pos;
	int			color;

	j = cy - 1;
	step.y = v.height / GUN_SIZE;
	step.x = v.width / GUN_SIZE;
	pos.y = 0.0;
	while (++j < cy + GUN_SIZE)
	{
		i = cx - 1;
		pos.x = 0.0;
		while (++i < cx + GUN_SIZE)
		{
			color = get_pixel_color(&v, (t_point){(int)pos.x, (int)pos.y}, 0);
			if (color != rgb(0, 255, 0))
				put_pixel(&data->screen, i, j, color);
			pos.x += step.x;
		}
		pos.y += step.y;
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
	put_gun_to_window(data, data->curr_sprites, (WIDTH / 2) \
	- (GUN_SIZE / 2), HEIGHT - GUN_SIZE);
	put_mini_map_to_window(map_frame, data, (HEIGHT - 5) - map_frame->height,
		5);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->screen.addr, 0, 0);
}

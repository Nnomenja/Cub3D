/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 01:47:43 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/18 12:43:45 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./map.h"

void	set_params(t_params *params, t_mini_map *mini_map, t_point p, t_point t)
{
	params->dx = p.x - mini_map->px - t.x;
	params->dy = p.y - mini_map->py - t.y;
	params->sx = round(mini_map->cos_a * params->dx - mini_map->sin_a
			* params->dy + mini_map->px);
	params->sy = round(mini_map->sin_a * params->dx + mini_map->cos_a
			* params->dy + mini_map->py);
}

void	setup_map_position(t_img *src, t_data *data, t_point t)
{
	t_img		tmp;
	t_params	params;
	int			y;
	int			x;
	int			color;

	y = -1;
	new_empty_frame(&tmp, data);
	while (++y < tmp.height)
	{
		x = -1;
		while (++x < tmp.width)
		{
			set_params(&params, &data->mini_map, (t_point){x, y}, t);
			color = get_pixel_color(src, (t_point){params.sx, params.sy}, 0);
			if (color != -1)
				put_pixel(&tmp, x, y, color);
			else
				put_pixel(&tmp, x, y, rgb(12, 238, 238));
		}
	}
	put_map_to_frame(&data->mini_map.frame, &tmp);
	mlx_destroy_image(data->mlx, tmp.addr);
}

void	render_map(t_data *data)
{
	t_mini_map	*mini_map;
	t_img		*backups;
	t_point		p;
	double		angle;

	mini_map = &data->mini_map;
	backups = &data->mini_map.backups;
	angle = deg_to_rad(270) - data->angle;
	set_player(data->player, &p);
	mini_map->cos_a = cos(angle * -1);
	mini_map->sin_a = sin(angle * -1);
	mini_map->px = p.x;
	mini_map->py = p.y;
	setup_map_position(backups, data, (t_point){mini_map->cx - p.x, mini_map->cy
		- p.y});
}

void	set_map_entities(t_mini_map *mini_map, t_data *data)
{
	t_img	*img;

	img = &mini_map->backups;
	img->width = MN_PIXEL * data->col;
	img->height = MN_PIXEL * data->row;
	img->addr = mlx_new_image(data->mlx, img->width, img->height);
	img->b_addr = mlx_get_data_addr(img->addr, &(img->bpp), &(img->size_line),
			&(img->endian));
	init_frame(&mini_map->frame, data->mlx);
	mini_map->cx = mini_map->frame.width / 2;
	mini_map->cy = mini_map->frame.height / 2;
	init_cursor(data);
	draw_map(data->map, data);
}

void	init_map(t_data *data)
{
	t_mini_map	*mini_map;

	mini_map = &data->mini_map;
	ajust_col(data->map, data->col);
	set_map_entities(mini_map, data);
	fill_space(data->map);
}

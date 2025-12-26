/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 04:59:16 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/24 13:54:29 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render_bonus.h"

void	draw_vertical_line(t_point start, int height, t_data *data, int color)
{
	int	i;
	int	j;
	int	start_x;
	int	start_y;

	start_x = (int)start.x;
	start_y = (int)start.y;
	j = start_y;
	while (j < (start_y + height))
	{
		i = start_x;
		while (i < (start_x + 1))
		{
			put_pixel(&data->screen, i, j, color);
			i++;
		}
		j++;
	}
}

void	draw_wall(t_data *data, int index, t_img *textures)
{
	int		i;
	int		j;
	double	k;
	double	step;
	t_ray	ray;

	ray = data->rays[index];
	step = textures->height / ray.line_length;
	k = ray.t_start;
	j = ray.start.y;
	i = ray.start.x;
	if (ray.line_length > HEIGHT)
		ray.line_length = HEIGHT;
	while (j < (ray.start.y + ray.line_length))
	{
		put_pixel(&data->screen, i, j++, get_pixel_color(textures,
				(t_point){(int)data->rays[i].offset, (int)k},
				data->rays[i].distance));
		k += step;
	}
}

void	draw_ceil(t_ray *ray, int color, int i, t_data *data)
{
	double	start_x;
	double	start_y;
	double	h;

	start_x = i;
	start_y = 0;
	h = ray->begin;
	draw_vertical_line((t_point){start_x, start_y}, h, data, color);
}

void	draw_floor(t_ray *ray, int color, int i, t_data *data)
{
	double	start_x;
	double	start_y;
	double	h;

	start_x = i;
	start_y = ray->begin + ray->line_length;
	h = HEIGHT - (ray->begin + ray->line_length) + 1;
	draw_vertical_line((t_point){start_x, start_y}, h, data, color);
}

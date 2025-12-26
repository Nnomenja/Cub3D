/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:42:49 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/24 13:54:29 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils_bonus.h"

t_point	pixel_position(t_point p, t_data *data)
{
	p.x = (p.x * data->col) / (data->col * PIXEL);
	p.y = (p.y * data->row) / (data->row * PIXEL);
	return (p);
}

double	distance(t_point start, t_point end)
{
	return (sqrt(pow((end.x - start.x), 2) + pow((end.y - start.y), 2)));
}

int	get_pixel_color(t_img *img, t_point p, double distance)
{
	unsigned int	color;

	if (p.x < 0 || p.y < 0 || p.x >= img->width || p.y >= img->height)
		return (-1);
	color = *(unsigned int *)(img->b_addr + ((int)p.y * img->size_line)
			+ ((int)p.x * (img->bpp / 8)));
	(void)distance;
	return (color);
}

void	put_pixel(t_img *target, int x, int y, int color)
{
	char	*dst;

	dst = target->b_addr + (y * target->size_line + x * (target->bpp / 8));
	*(unsigned int *)dst = color;
}

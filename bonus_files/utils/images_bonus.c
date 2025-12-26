/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 22:21:23 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/24 13:54:29 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils_bonus.h"

bool	img_addr(char *path, void *mlx, t_img *target)
{
	target->addr = mlx_xpm_file_to_image(mlx, \
	without_spaces(path), &target->width,
			&target->height);
	if (!target->addr)
		return (false);
	target->b_addr = mlx_get_data_addr(target->addr, &target->bpp,
			&target->size_line, &target->endian);
	if (!target->b_addr)
		return (false);
	return (true);
}

void	assign_img(t_img src, t_img *dst)
{
	dst->addr = src.addr;
	dst->b_addr = src.b_addr;
	dst->bpp = src.bpp;
	dst->endian = src.endian;
	dst->width = src.width;
	dst->height = src.height;
	dst->size_line = src.size_line;
}

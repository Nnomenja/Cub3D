/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:39:29 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/25 09:34:01 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include "../basic_utils/basic_utils_bonus.h"
# include "../cub3d_bonus.h"

/*------- Angle -------*/
double	deg_to_rad(int value);
double	rad_to_deg(double value);
double	normalize_angle(double v);
int		comprise(float angle, int min, int max);
/*------- Color -------*/
int		rgb(int r, int g, int b);
int		get_color(char *color_data_str);
/*------- Pixel -------*/
t_point	pixel_position(t_point p, t_data *data);
double	distance(t_point start, t_point end);
int		get_pixel_color(t_img *img, t_point p, double distance);
void	put_pixel(t_img *target, int x, int y, int color);
/*------- Free -------*/
void	ft_free(char **s);
/*------- Images -------*/
bool	img_addr(char *path, void *mlx, t_img *target);
void	assign_img(t_img src, t_img *dst);

#endif
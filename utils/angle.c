/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:04:50 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/08 10:14:06 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

double	deg_to_rad(int value)
{
	return ((value * PI) / 180.0);
}

double	rad_to_deg(double value)
{
	return ((value * 180.0) / PI);
}

double	normalize_angle(double v)
{
	if (v >= (2 * PI))
		v -= 2 * PI;
	if (v < 0)
		v += (2 * PI);
	return (v);
}

int	comprise(float angle, int min, int max)
{
	return (normalize_angle(angle) >= deg_to_rad(min)
		&& normalize_angle(angle) <= deg_to_rad(max));
}

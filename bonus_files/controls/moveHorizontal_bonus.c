/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveHorizontal_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:40:45 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/24 13:54:29 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./controls_bonus.h"

void	move_horizontal(int keycode, double angle, t_data *data)
{
	double	tmp;
	float	d;

	if (keycode == XK_a || keycode == XK_d)
	{
		d = -1.0;
		if (keycode == XK_d)
			d = 1.0;
		tmp = angle;
		data->angle = normalize_angle(angle + (deg_to_rad(90) * d));
		forward(data, data->move_speed);
		data->angle = tmp;
	}
}

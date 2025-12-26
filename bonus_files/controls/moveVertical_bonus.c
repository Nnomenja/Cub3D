/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveVertical_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:59:55 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/24 13:54:29 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./controls_bonus.h"

void	forward(t_data *data, int moveStep)
{
	t_n		c;
	t_n		t;
	t_point	p;
	float	angle;

	p = data->player;
	angle = data->angle;
	get_collision(&c, p);
	collision(data->player, data->map, c, &t);
	if ((t.tl && comprise(angle, 180, 270)) || (t.tr && comprise(angle, 270,
				360)) || (t.br && comprise(angle, 0, 90)) || (t.bl
			&& comprise(angle, 90, 180)))
		return ;
	if (!(c.l && t.l && comprise(angle, 90, 270)) && !(c.r && t.r
			&& !comprise(angle, 90, 270)))
	{
		data->player.x += cos(angle) * moveStep;
	}
	if (!(c.t && t.t && !comprise(angle, 0, 180)) && !(c.b && t.b
			&& comprise(angle, 0, 180)))
	{
		data->player.y += sin(angle) * moveStep;
	}
}

static void	backward(t_data *data, int moveStep)
{
	t_n		c;
	t_n		t;
	t_point	p;
	float	angle;

	p = data->player;
	angle = data->angle;
	get_collision(&c, p);
	collision(data->player, data->map, c, &t);
	if ((t.tl && comprise(angle, 0, 90)) || (t.tr && comprise(angle, 90, 180))
		|| (t.br && comprise(angle, 180, 270)) || (t.bl && comprise(angle, 270,
				360)))
		return ;
	if (!(c.l && t.l && !comprise(angle, 90, 270)) && !(c.r && t.r
			&& comprise(angle, 90, 270)))
	{
		data->player.x += cos(angle) * moveStep;
	}
	if (!(c.t && t.t && comprise(angle, 0, 180)) && !(c.b && t.b
			&& !comprise(angle, 0, 180)))
	{
		data->player.y += sin(angle) * moveStep;
	}
}

void	move_vertical(int walk_direction, t_data *data, double moveStep)
{
	if (walk_direction == 1)
		forward(data, moveStep);
	else
		backward(data, moveStep);
}

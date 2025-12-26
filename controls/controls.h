/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:01:03 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/17 09:58:26 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

# include "../cub3d.h"
# include "../render/render.h"
# include "../utils/utils.h"
# include "../event/event.h"

/*------- Collision -------*/
void	get_collision(t_n *n, t_point p);
void	collision(t_point p, char **map, t_n c, t_n *t);
/*------- Move -------*/
void	move_horizontal(int keycode, double angle, t_data *data);
void	move_vertical(int walk_direction, t_data *data, double moveStep);
void	forward(t_data *data, int moveStep);
int		move_player(int keycode, void *param);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:01:03 by nnomenja          #+#    #+#             */
/*   Updated: 2025/12/06 11:56:15 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_BONUS_H
# define CONTROLS_BONUS_H

# include "../cub3d_bonus.h"
# include "../event/event_bonus.h"
# include "../render/render_bonus.h"
# include "../utils/utils_bonus.h"

# define GATE_SPEED 1
# define CL "1C"
# define CLOSE 1
# define OPEN -1

/*------- Collision -------*/
void	get_collision(t_n *n, t_point p);
void	collision(t_point p, char **map, t_n c, t_n *t);
bool	is_block(int c);

/*------- Move -------*/
void	move_horizontal(int keycode, double angle, t_data *data);
void	move_vertical(int walk_direction, t_data *data, double moveStep);
void	forward(t_data *data, int moveStep);
int		move_player(int keycode, void *param);
void	in_front_of_gate(t_data *data);

/*------- Gate -------*/
int		handle_gate_loop(void *params);
void	auto_hide_gate(t_data *data);
void	handle_the_gate(t_data *data);

/*------- Gate utiles -------*/
bool	current_gates(t_point end, t_type t, t_data *data);
void	on_enter_gate(char **map, t_point p, t_data *data);
void	in_front_of_gate(t_data *data);
bool	gate_orientation(t_point p, char **map, t_type type);

#endif
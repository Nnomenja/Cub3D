/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 09:45:54 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/25 09:34:01 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_BONUS_H
# define HOOKS_BONUS_H

# include "../controls/controls_bonus.h"
# include "../cub3d_bonus.h"

void	key_hooks(t_data *data);
void	mouse_hooks(t_data *data);
void	loop_hooks(t_data *data);
void	mouse_release(t_data *data);

#endif
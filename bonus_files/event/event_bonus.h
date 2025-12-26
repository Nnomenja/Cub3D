/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:05:03 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/25 09:34:01 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_BONUS_H
# define EVENT_BONUS_H

# include "../cub3d_bonus.h"
# include "../inits/init_bonus.h"
# include "../controls/controls_bonus.h"

int	close_window(t_data *data);
int	mouse_leave(void *params);
int	mouse_move(int x, int y, void *params);

#endif  
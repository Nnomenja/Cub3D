/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:05:03 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/17 15:59:15 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "../cub3d.h"
# include "../inits/init.h"
# include "../controls/controls.h"

int	close_window(t_data *data);
int	mouse_leave(void *params);
int	mouse_move(int x, int y, void *params);

#endif  
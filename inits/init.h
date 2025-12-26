/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:56:32 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/07 02:20:47 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "../cub3d.h"
# include "../event/event.h"
# include "../parse/parse.h"
# include "../utils/utils.h"
# include "../mini-map/map.h"

/*------- Windows -------*/
bool	init(t_data *data);
/*------- Clean -------*/
void	cleanup_texture(t_data *data);
void	cleanup_all(t_map_data map_data, t_data *data);

#endif
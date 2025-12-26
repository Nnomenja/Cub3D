/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:56:32 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/25 09:34:01 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_BONUS_H
# define INIT_BONUS_H

# define SPRITES_FILE "./textures/sprites/0.xpm"

# include "../cub3d_bonus.h"
# include "../event/event_bonus.h"
# include "../mini-map/map_bonus.h"
# include "../parse/parse_bonus.h"
# include "../utils/utils_bonus.h"

typedef struct s_is
{
	int		i;
	char	n;
	t_img	*tmp;
	int		len;
	char	*dup_path;
}	t_is;

/*------- Windows -------*/
bool	init(t_data *data);
/*------- Clean -------*/
void	cleanup_texture(t_data *data);
void	cleanup_all(t_map_data map_data, t_data *data);
void	clean_sprites(t_data *data);
/*------- Sprites -------*/
bool	init_sprites(t_data *data, char *pathname);

#endif

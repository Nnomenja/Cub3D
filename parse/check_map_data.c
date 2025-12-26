/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 05:30:26 by toloandr          #+#    #+#             */
/*   Updated: 2025/11/24 14:43:45 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parse.h"

int	check_map_data(t_map_data map_data, t_point *p, t_data *data)
{
	if (missing_data(map_data))
		return (0);
	if (!check_color_data(map_data))
		return (print_error("Invalid color data\n"), 0);
	if (!check_paths(map_data))
		return (print_error("Invalid texture path(s)\n"), 0);
	if (!check_map(map_data, p, data))
		return (0);
	return (1);
}

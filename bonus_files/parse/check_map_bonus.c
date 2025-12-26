/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 05:27:12 by toloandr          #+#    #+#             */
/*   Updated: 2025/12/06 19:43:22 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parse_bonus.h"

static int	check_successive_newlines(char *map)
{
	while (*map && *(map + 1))
	{
		if (*map == '\n' && *(map + 1) == '\n')
			return (print_error("Successive newlines in map\n"), 1);
		map++;
	}
	return (0);
}

int	check_map(t_map_data map_data, t_point *p, t_data *data)
{
	char	**map;
	int		px;
	int		py;

	if (check_successive_newlines(map_data.map) == 1)
		return (0);
	map = ft_split(map_data.map, '\n');
	if (!map)
		return (print_error("Failed to split map\n"), 0);
	if (!check_valid_chars(map))
		return (free_split(map), print_error("Invalid character in map\n"), 0);
	if (!find_player(map, &px, &py))
		return (free_split(map), print_error("Player missing or duplicated\n"),
			0);
	if (!flood_fill(map, py, px))
		return (free_split(map), 0);
	if (!check_int_map(map))
		return (free_split(map), print_error("Map open\n"), 0);
	free_split(map);
	data->map = ft_split(map_data.map, '\n');
	data->px = px;
	data->py = py;
	p->x = ((px + 1) * PIXEL) - (PIXEL / 2);
	p->y = ((py + 1) * PIXEL) - (PIXEL / 2);
	return (1);
}

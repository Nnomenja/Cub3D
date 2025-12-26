/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 05:11:54 by toloandr          #+#    #+#             */
/*   Updated: 2025/11/25 10:20:16 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parse_bonus.h"

int	char_in_list(char c, char *list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		if (c == list[i])
			return (1);
		i++;
	}
	return (0);
}

int	chars_in_str(char *str, char *list)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!char_in_list(str[i], list))
			return (0);
		i++;
	}
	return (1);
}

int	check_valid_chars(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!chars_in_str(map[i], " 01NSEWC"))
			return (0);
		i++;
	}
	return (1);
}

int	find_player(char **map, int *px, int *py)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	y = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' ||
				map[y][x] == 'E' || map[y][x] == 'W')
			{
				*px = x;
				*py = y;
				count++;
			}
			x++;
		}
		y++;
	}
	return (count == 1);
}

int	flood_fill(char **map, int y, int x)
{
	if (y < 0 || x < 0 || !map[y] || !map[y][x] || map[y][x] == ' ')
	{
		print_error("Map is open\n");
		return (0);
	}
	if (map[y][x] == '1' || map[y][x] == 'F')
		return (1);
	map[y][x] = 'F';
	if (!flood_fill(map, y + 1, x))
		return (0);
	if (!flood_fill(map, y - 1, x))
		return (0);
	if (!flood_fill(map, y, x + 1))
		return (0);
	if (!flood_fill(map, y, x - 1))
		return (0);
	return (1);
}

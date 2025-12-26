/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:50:25 by toloandr          #+#    #+#             */
/*   Updated: 2025/12/07 11:30:06 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parse.h"

static int	check_width_borders(int **int_map, int w, int h)
{
	int	j;

	j = 0;
	while (j < w)
	{
		if (int_map[0][j] == 0)
			return (0);
		j++;
	}
	j = 0;
	while (j < w)
	{
		if (int_map[h - 1][j] == 0)
			return (0);
		j++;
	}
	return (1);
}

static int	check_height_borders(int **int_map, int w, int h)
{
	int	i;

	i = 0;
	while (i < h)
	{
		if (int_map[i][0] == 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < h)
	{
		if (int_map[i][w - 1] == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	check_zero_neighbors(int	**int_map, int i, int j)
{
	if (int_map[i - 1][j] == -1)
		return (0);
	if (int_map[i + 1][j] == -1)
		return (0);
	if (int_map[i][j - 1] == -1)
		return (0);
	if (int_map[i][j + 1] == -1)
		return (0);
	return (1);
}

static int	check_non_borders(int **int_map, int w, int h)
{
	int	i;
	int	j;

	i = 1;
	while (i < h - 1)
	{
		j = 1;
		while (j < w - 1)
		{
			if (int_map[i][j] == 0)
			{
				if (!check_zero_neighbors(int_map, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_int_map(char **map)
{
	t_map_conv	m;

	m = str_map_to_int_map(map);
	if (!check_width_borders(m.int_map, m.w, m.h))
		return (free_int_map(m.int_map, m.h), 0);
	if (!check_height_borders(m.int_map, m.w, m.h))
		return (free_int_map(m.int_map, m.h), 0);
	if (!check_non_borders(m.int_map, m.w, m.h))
		return (free_int_map(m.int_map, m.h), 0);
	return (free_int_map(m.int_map, m.h), 1);
}

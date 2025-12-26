/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:50:25 by toloandr          #+#    #+#             */
/*   Updated: 2025/12/07 11:29:58 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parse.h"

static int	convert_char(char c)
{
	if (c == ' ')
		return (-1);
	if (c == '0')
		return (0);
	if (c == '1')
		return (1);
	if (c == 'N')
		return (2);
	if (c == 'S')
		return (3);
	if (c == 'E')
		return (4);
	if (c == 'W')
		return (5);
	if (c == 'F')
		return (6);
	return (-1);
}

static int	get_height(char **map)
{
	int	h;
	int	i;

	h = 0;
	i = 0;
	while (map[i])
	{
		h++;
		i++;
	}
	return (h);
}

static int	get_width(char **map)
{
	int	i;
	int	max;
	int	len;

	i = 0;
	max = 0;
	while (map[i])
	{
		len = 0;
		while (map[i][len])
			len++;
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

static void	fill_row(int *row, char *line, int w)
{
	int	j;
	int	len;

	len = str_len(line);
	j = 0;
	while (j < w)
	{
		if (j < len)
			row[j] = convert_char(line[j]);
		else
			row[j] = -1;
		j++;
	}
}

t_map_conv	str_map_to_int_map(char **map)
{
	t_map_conv	mb;

	mb.h = get_height(map);
	mb.w = get_width(map);
	mb.int_map = malloc(sizeof(int *) * mb.h);
	mb.i = 0;
	while (mb.i < mb.h)
	{
		mb.int_map[mb.i] = malloc(sizeof(int) * mb.w);
		fill_row(mb.int_map[mb.i], map[mb.i], mb.w);
		mb.i++;
	}
	return (mb);
}

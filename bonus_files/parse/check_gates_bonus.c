/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_gates_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:58:21 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/25 09:48:09 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parse_bonus.h"

static bool	is_empty(int c)
{
	int	i;

	i = -1;
	while (EMPTY[++i])
	{
		if (EMPTY[i] == c)
			return (true);
	}
	return (false);
}

static bool	check_overflow(int i, int j, char **map)
{
	if ((i - 1) < 0 || i + 1 == str_len(map[j]) || j - 1 < 0 || !map[j + 1])
		return (false);
	return (true);
}

static bool	check_gate_wall(char **map, int i, int j)
{
	return (!(((is_empty(map[j + 1][i]) && is_empty(map[j - 1][i]) \
	&& map[j][i - 1] == '1' && map[j][i + 1] == '1')) || \
	(map[j + 1][i] == '1' && map[j - 1][i] == '1' \
	&& is_empty(map[j][i - 1]) && is_empty(map[j][i + 1]))));
}

bool	check_gates(char **map)
{
	int	j;
	int	i;

	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == 'C')
			{
				if (!check_overflow(i, j, map))
					return (print_error(EG1), false);
				if (map[j + 1][i] == 'C' || map[j - 1][i] == 'C'
					|| map[j][i + 1] == 'C' || map[j][i - 1] == 'C')
					return (print_error(EG0), false);
				if (check_gate_wall(map, i, j))
					return (print_error(EG1), false);
			}
		}
	}
	return (true);
}

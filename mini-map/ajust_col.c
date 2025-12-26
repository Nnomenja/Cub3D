/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ajust_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:01:19 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/18 12:45:45 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./map.h"

static char	*new_space(int size)
{
	char	*res;

	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	res[size] = '\0';
	while (size--)
	{
		res[size] = ' ';
	}
	return (res);
}

void	ajust_col(char **map, int col)
{
	int		i;
	int		len;
	int		sub;
	char	*add;

	i = -1;
	while (map[++i])
	{
		len = str_len(map[i]);
		sub = col - len;
		if (sub > 0)
		{
			add = new_space(sub);
			map[i] = str_n_join(map[i], add, sub);
			ft_free(&add);
		}
	}
}

void	fill_space(char **map)
{
	int	j;
	int	i;

	j = -1;
	while (map[++j])
	{
		i = -1;
		while (++i < str_len(map[j]))
		{
			if (map[j][i] == ' ')
				map[j][i] = '1';
		}
	}
}

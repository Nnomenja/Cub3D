/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 05:11:10 by toloandr          #+#    #+#             */
/*   Updated: 2025/11/24 14:44:17 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parse.h"

int	check_path_(char *path)
{
	int	fd;

	fd = open(without_spaces(path), O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	count_word(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != ' ' && str[i] != '\t')
				i++;
		}
	}
	return (count);
}

int	validate_path(char *path, int offset)
{
	if (count_word(path) != 2)
		return (0);
	return (check_path_(path + offset));
}

int	check_paths(t_map_data map_data)
{
	if (map_data.no && !validate_path(map_data.no, 3))
		return (0);
	if (map_data.so && !validate_path(map_data.so, 3))
		return (0);
	if (map_data.ea && !validate_path(map_data.ea, 3))
		return (0);
	if (map_data.we && !validate_path(map_data.we, 3))
		return (0);
	return (1);
}

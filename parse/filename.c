/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 18:31:00 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/08 10:07:00 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../basic_utils/basic_utils.h"
#include "../cub3d.h"

static bool	check_exension(char *name, int size)
{
	if (size <= str_len(MAP_EXTESION))
		return (false);
	return (!str_n_cmp(&name[size - 4], MAP_EXTESION, str_len(MAP_EXTESION)));
}

static bool	check_path(char *name)
{
	size_t	len;

	len = str_len(name);
	if (!check_exension(name, len))
		return (false);
	while (--len)
	{
		if (name[len] == '.' && (len - 1) != 0 && name[len - 1] == '/')
			return (false);
	}
	return (true);
}

int	map_fd(char *name)
{
	int	fd;

	if (!check_path(name))
		exit_error(EMF0);
	fd = open(name, O_RDONLY);
	if (fd == -1)
		exit_error(EMF1);
	return (fd);
}

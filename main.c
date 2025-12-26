/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:45:09 by nnomenja          #+#    #+#             */
/*   Updated: 2025/12/06 10:50:45 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./controls/controls.h"
#include "./hooks/hooks.h"
#include "./inits/init.h"
#include "./parse/parse.h"
#include "./render/render.h"
#include "./utils/utils.h"
#include "cub3d.h"

int	main(int ac, char **av)
{
	char	*map;
	int		fd_map;
	t_data	data;

	if (ac != 2)
		return (print_error("Usage: <program_name> <map>"), 1);
	fd_map = map_fd(av[1]);
	map = read_map(fd_map);
	data.map_data = get_map_data(map);
	if (!check_map_data(data.map_data, &data.player, &data))
	{
		free_map_data(&data.map_data);
		ft_free(&map);
		return (1);
	}
	if (!init(&data))
		return (print_error("Failed to init data"), ft_free(&map), 1);
	ft_free(&map);
	render(&data);
	key_hooks(&data);
	loop_hooks(&data);
	free_map_data(&data.map_data);
	return (0);
}

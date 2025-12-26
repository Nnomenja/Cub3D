/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:45:09 by nnomenja          #+#    #+#             */
/*   Updated: 2025/12/01 00:06:08 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./controls/controls_bonus.h"
#include "./inits/init_bonus.h"
#include "./parse/parse_bonus.h"
#include "./render/render_bonus.h"
#include "./utils/utils_bonus.h"
#include "./hooks/hooks_bonus.h"
#include "cub3d_bonus.h"

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
	mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	key_hooks(&data);
	mouse_hooks(&data);
	loop_hooks(&data);
	free_map_data(&data.map_data);
	return (0);
}

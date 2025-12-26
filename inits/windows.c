/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:19:54 by nnomenja          #+#    #+#             */
/*   Updated: 2025/12/06 10:53:41 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./init.h"

double	player_orientation(char **map, t_data *data)
{
	double	res;
	int		x;
	int		y;

	x = data->px;
	y = data->py;
	if (map[y][x] == 'E')
		res = 0;
	else if (map[y][x] == 'S')
		res = 90;
	else if (map[y][x] == 'W')
		res = 180;
	else
		res = 270;
	return (deg_to_rad(res));
}

bool	init_textures(t_map_data map_data, t_data *data)
{
	data->no.addr = NULL;
	data->so.addr = NULL;
	data->ea.addr = NULL;
	data->we.addr = NULL;
	data->screen.addr = NULL;
	data->mini_map.cursor.addr = NULL;
	data->mini_map.frame.addr = NULL;
	data->mini_map.backups.addr = NULL;
	if (!img_addr(map_data.no + 3, data->mlx, &(data->no)))
		return (false);
	if (!img_addr(map_data.so + 3, data->mlx, &(data->so)))
		return (false);
	if (!img_addr(map_data.ea + 3, data->mlx, &(data->ea)))
		return (false);
	if (!img_addr(map_data.we + 3, data->mlx, &(data->we)))
		return (false);
	return (true);
}

static int	max_col(char **map)
{
	int	i;
	int	max;
	int	len;

	max = 0;
	i = -1;
	while (map[++i])
	{
		len = str_len(map[i]);
		if (max < len)
			max = len;
	}
	return (max);
}

void	init_screen(t_data *data)
{
	int	j;

	data->screen.addr = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->screen.b_addr = mlx_get_data_addr(data->screen.addr, \
	&(data->screen.bpp), &(data->screen.size_line), &(data->screen.endian));
	data->col = max_col(data->map);
	j = -1;
	while (data->map[++j])
		;
	data->row = j;
	data->px = WIDTH / data->col;
	data->py = HEIGHT / data->row;
	data->w = data->col * PIXEL;
	data->h = data->row * PIXEL;
	data->move_speed = 8;
	data->rotate_speed = .1f;
	mlx_mouse_move(data->mlx, data->mlx_win, WIDTH / 2, HEIGHT / 2);
	data->mouse_x = WIDTH / 2;
	data->move = false;
	data->walk_direction = 0;
	data->turn_direction = 0;
}

bool	init(t_data *data)
{
	t_map_data	*map_data;

	map_data = &data->map_data;
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free_split(data->map);
		return (free_map_data(map_data), false);
	}
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	if (!data->mlx_win)
	{
		free_split(data->map);
		free_map_data(map_data);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (false);
	}
	data->angle = player_orientation(data->map, data);
	if (!init_textures(*map_data, data))
		return (free_split(data->map), cleanup_all(*map_data, data), false);
	init_screen(data);
	init_map(data);
	return (true);
}

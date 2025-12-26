/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:16:22 by toloandr          #+#    #+#             */
/*   Updated: 2025/11/25 09:42:29 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parse.h"

static bool	check_extension(char *name, int size)
{
	if (size <= str_len(".xpm"))
		return (false);
	if (str_n_cmp(&name[size - 4], ".xpm", str_len(".xpm")))
	{
		print_error("texture filename error");
		return (false);
	}
	return (true);
}

int	fill_map_data(t_map_data *map_data, char *tok)
{
	if (str_n_cmp(tok, "NO ", 3) == 0 \
	&& check_extension(tok, str_len(tok)))
		map_data->no = str_dup(tok);
	else if (str_n_cmp(tok, "SO ", 3) == 0 \
	&& check_extension(tok, str_len(tok)))
		map_data->so = str_dup(tok);
	else if (str_n_cmp(tok, "EA ", 3) == 0 \
	&& check_extension(tok, str_len(tok)))
		map_data->ea = str_dup(tok);
	else if (str_n_cmp(tok, "WE ", 3) == 0 \
	&& check_extension(tok, str_len(tok)))
		map_data->we = str_dup(tok);
	else if (str_n_cmp(tok, "C ", 2) == 0)
		map_data->c = str_dup(tok);
	else if (str_n_cmp(tok, "F ", 2) == 0)
		map_data->f = str_dup(tok);
	else
		return (0);
	return (1);
}

t_map_data	get_map_data(char *map)
{
	t_vars	v;

	v.dup_map = str_dup(map);
	v.dup_map_head = v.dup_map;
	v.map_data = (t_map_data){NULL, NULL, NULL, NULL, NULL, NULL, NULL};
	v.i = 0;
	v.tok = str_tok(v.dup_map, "\n");
	while (v.tok && v.i < 6)
	{
		if (fill_map_data(&v.map_data, v.tok) == 0)
			return (free(v.dup_map), v.map_data);
		v.tok = str_tok(NULL, "\n");
		v.i++;
	}
	v.map_pos = v.tok - v.dup_map_head;
	v.map_data.map = str_dup(map + v.map_pos);
	free(v.dup_map);
	return (v.map_data);
}

void	free_map_data(t_map_data *map_data)
{
	free(map_data->no);
	free(map_data->so);
	free(map_data->ea);
	free(map_data->we);
	free(map_data->f);
	free(map_data->c);
	ft_free(&(map_data->map));
}

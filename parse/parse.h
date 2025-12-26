/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:36:24 by toloandr          #+#    #+#             */
/*   Updated: 2025/12/06 18:08:58 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../cub3d.h"
# include "../basic_utils/basic_utils.h"
# include "../utils/utils.h"

typedef struct s_vars
{
	int			i;
	char		*dup_map;
	char		*dup_map_head;
	char		*tok;
	int			map_pos;
	t_map_data	map_data;
}				t_vars;

typedef struct s_map_conv
{
	int	h;
	int	w;
	int	**int_map;
	int	i;
	int	j;
}	t_map_conv;

char			*read_map(int fd);
t_map_data		get_map_data(char *map);
void			free_map_data(t_map_data *map_data);

int				check_path_(char *path);
int				count_word(char *str);
int				validate_path(char *path, int offset);
int				check_paths(t_map_data map_data);
int				check_color_data(t_map_data map_data);
int				char_in_list(char c, char *list);
int				chars_in_str(char *str, char *list);
int				check_valid_chars(char **map);
int				find_player(char **map, int *px, int *py);
int				flood_fill(char **map, int y, int x);
int				check_map(t_map_data map_data, t_point *p, t_data *data);
int				missing_data(t_map_data map_data);
int				check_map_data(t_map_data map_data, t_point *p, t_data *data);
int				map_fd(char *name);

t_map_conv		str_map_to_int_map(char **map);
int				check_int_map(char **map);
void			free_int_map(int **map, int h);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:36:24 by toloandr          #+#    #+#             */
/*   Updated: 2025/12/06 19:39:39 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_BONUS_H
# define PARSE_BONUS_H

# include "../cub3d_bonus.h"
# include "../basic_utils/basic_utils_bonus.h"
# include "../utils/utils_bonus.h"

# define EMPTY "0NWSE"
# define EG0 "the gate should not be consecutive"
# define EG1 "the gate should only surrond by two walls"

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
bool			check_gates(char **map);

t_map_conv		str_map_to_int_map(char **map);
int				check_int_map(char **map);
void			free_int_map(int **map, int h);

#endif

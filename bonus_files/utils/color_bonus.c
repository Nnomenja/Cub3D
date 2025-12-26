/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 20:55:11 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/24 13:54:29 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils_bonus.h"

int	rgb(int r, int g, int b)
{
	int	res;

	res = r << 16 | g << 8 | b;
	return (res);
}

int	get_color(char *color_data_str)
{
	int		i;
	char	*tmp;
	char	*tok;
	int		field[3];

	tmp = str_dup(color_data_str + 2);
	tok = str_tok(tmp, ",");
	i = 0;
	while (tok && i < 3)
	{
		field[i] = ft_atoi(tok);
		tok = str_tok(NULL, ",");
		i++;
	}
	free(tmp);
	return (rgb(field[0], field[1], field[2]));
}

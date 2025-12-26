/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 05:11:32 by toloandr          #+#    #+#             */
/*   Updated: 2025/11/24 14:43:58 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parse.h"

static int	format_correct(int c)
{
	if (c == ',' || (c >= '0' && c <= '9') || (c == ' ' || c == '\t'))
		return (1);
	return (0);
}

static int	check_data(char *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (data[i])
	{
		if (data[i] == ',')
			count++;
		if (!format_correct(data[i]))
			return (0);
		i++;
	}
	if (count > 2)
		return (0);
	return (1);
}

static int	contains_digit(char *token)
{
	int	count;

	count = 0;
	while (*token && !is_digit(*token))
		token++;
	while (*token && is_digit(*token))
	{
		if (is_digit(*token))
			count++;
		token++;
	}
	while (*token && !is_digit(*token))
		token++;
	if (count == 0 || *token)
		return (0);
	return (1);
}

static int	validate_rgb(char *data)
{
	char	*data_dup;
	char	*head;
	char	*token;
	int		value;
	int		count;

	data_dup = str_dup(data);
	if (!data_dup)
		return (0);
	head = data_dup;
	data_dup += 2;
	count = 0;
	token = str_tok(data_dup, ",");
	while (token)
	{
		if (!contains_digit(token))
			return (free(head), 0);
		value = ft_atoi(token);
		if (value < 0 || value > 255)
			return (free(head), 0);
		count++;
		token = str_tok(NULL, ",");
	}
	return (free(head), count == 3);
}

int	check_color_data(t_map_data map_data)
{
	if (map_data.f && !check_data(map_data.f + 2))
		return (0);
	if (map_data.c && !check_data(map_data.c + 2))
		return (0);
	if (map_data.f && !validate_rgb(map_data.f))
		return (0);
	if (map_data.c && !validate_rgb(map_data.c))
		return (0);
	return (1);
}

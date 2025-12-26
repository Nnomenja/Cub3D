/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dup_delim_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:14:35 by toloandr          #+#    #+#             */
/*   Updated: 2025/11/24 13:54:29 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./basic_utils_bonus.h"

static char	*str_n_dup(char *str, int n)
{
	int		i;
	char	*res;

	res = malloc(sizeof(char) * (n + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < n && str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*str_dup_delim(char *token)
{
	int	i;

	i = 0;
	if (token[i] && (token[i] > '0' && token[i] <= '9'))
		return (str_n_dup(token, 1));
	while (token[i] && (is_alnum(token[i]) || token[i] == '_'))
		i++;
	return (str_n_dup(token, i));
}

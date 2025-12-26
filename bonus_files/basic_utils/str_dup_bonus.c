/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:52:42 by toloandr          #+#    #+#             */
/*   Updated: 2025/11/24 13:54:29 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./basic_utils_bonus.h"

char	*str_dup(char *str)
{
	int		i;
	char	*res;

	if (!str)
		return (NULL);
	res = malloc(sizeof(char) * (str_len(str) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*str)
		res[i++] = (*str++);
	res[i] = '\0';
	return (res);
}

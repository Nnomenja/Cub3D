/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:52:42 by toloandr          #+#    #+#             */
/*   Updated: 2025/11/05 23:13:31 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./basic_utils.h"

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

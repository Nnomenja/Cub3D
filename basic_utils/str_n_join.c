/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_n_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:59:57 by toloandr          #+#    #+#             */
/*   Updated: 2025/11/05 23:13:30 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./basic_utils.h"

char	*str_n_join(char *str, char *to_join, int n)
{
	int		len;
	int		i;
	char	*res;

	if (!to_join)
		return (str);
	len = str_len(str);
	res = malloc(sizeof(char) * (len + n + 1));
	if (!res)
		return (str);
	i = 0;
	if (str)
	{
		while (str[i])
		{
			res[i] = str[i];
			i++;
		}
	}
	while (*to_join && n--)
		res[i++] = *to_join++;
	res[i] = '\0';
	free(str);
	return (res);
}

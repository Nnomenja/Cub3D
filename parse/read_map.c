/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 01:45:49 by toloandr          #+#    #+#             */
/*   Updated: 2025/11/24 14:44:21 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parse.h"

char	*read_map(int fd)
{
	int		br;
	char	buff[42 + 1];
	char	*res;

	res = NULL;
	br = 1;
	while (br > 0)
	{
		br = read(fd, buff, 42);
		if (br <= 0)
			break ;
		buff[br] = '\0';
		res = str_n_join(res, buff, br);
	}
	return (res);
}

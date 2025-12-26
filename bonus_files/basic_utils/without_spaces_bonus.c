/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   without_spaces_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:21:30 by toloandr          #+#    #+#             */
/*   Updated: 2025/11/27 13:24:47 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./basic_utils_bonus.h"

char	*without_spaces(char *path)
{
	char	*res;

	res = path;
	while (*res == ' ')
		res++;
	return (res);
}

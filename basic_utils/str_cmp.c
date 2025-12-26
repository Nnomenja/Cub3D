/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:45:28 by toloandr          #+#    #+#             */
/*   Updated: 2025/11/05 23:15:40 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./basic_utils.h"

int	str_cmp(char *str1, char *str2)
{
	if (!str1 || !str2)
		return (0);
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (0);
		str1++;
		str2++;
	}
	return ((*str1 == '\0') && (*str2 == '\0'));
}

int	str_cmp_(char *str1, char *str2)
{
	if (!str1 || !str2)
		return (str1 - str2);
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}

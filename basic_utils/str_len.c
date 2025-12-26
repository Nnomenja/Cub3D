/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:53:33 by toloandr          #+#    #+#             */
/*   Updated: 2025/11/05 23:15:35 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./basic_utils.h"

int	str_len(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

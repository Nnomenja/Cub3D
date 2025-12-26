/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:39:20 by toloandr          #+#    #+#             */
/*   Updated: 2025/11/05 23:13:31 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./basic_utils.h"

void	put_str(char *str)
{
	write(1, str, str_len(str));
}

void	put_str_fd(int fd, char *str)
{
	write(fd, str, str_len(str));
}

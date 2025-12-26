/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 22:35:34 by toloandr          #+#    #+#             */
/*   Updated: 2025/11/05 23:13:31 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./basic_utils.h"

void	print_error(char *err)
{
	static int	i = 0;

	if (i == 0)
		write(STDERR_FILENO, "Error\n", str_len("Error\n"));
	write(STDERR_FILENO, err, str_len(err));
	write(STDERR_FILENO, "\n", 1);
	i++;
}

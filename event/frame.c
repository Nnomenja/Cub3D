/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnomenja <nnomenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:04:14 by nnomenja          #+#    #+#             */
/*   Updated: 2025/11/17 16:22:20 by nnomenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./event.h"

int	close_window(t_data *data)
{
	free_split(data->map);
	cleanup_all(data->map_data, data);
	exit(0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_missing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 05:12:35 by toloandr          #+#    #+#             */
/*   Updated: 2025/11/24 14:43:54 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parse.h"

int	missing_data(t_map_data map_data)
{
	if (!map_data.no || !map_data.so || !map_data.ea || !map_data.we
		|| !map_data.f || !map_data.c || !map_data.map)
	{
		print_error("Data missing\n");
		return (1);
	}
	return (0);
}

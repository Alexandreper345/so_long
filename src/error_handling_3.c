/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:17:27 by alda-sil          #+#    #+#             */
/*   Updated: 2025/03/25 16:44:47 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_invalid(t_list *map, int x, int y)
{
	char	c;

	c = map->matriz[y][x];
	if (c != 'P' && c != 'E' && c != 'C' && c != '0' && c != '1' && c != '\0')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

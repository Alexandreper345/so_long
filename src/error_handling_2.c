/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:41:55 by alda-sil          #+#    #+#             */
/*   Updated: 2025/03/25 19:39:08 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	char_verification(int count_p, int count_e, int count_c)
{	
	if (count_p != 1)
		return (EXIT_FAILURE);
	else if (count_e != 1)
		return (EXIT_FAILURE);
	else if (count_c < 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	count_char(t_list *map, int y, t_int *index)
{
	int	x;

	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map_invalid(map, x, y))
				return (EXIT_FAILURE);
			if (map->matriz[y][x] == 'P')
				index->count_p++;
			else if (map->matriz[y][x] == 'E')
				index->count_e++;
			else if (map->matriz[y][x] == 'C')
				index->count_c++;
			x++;
		}
		y++;
	}
	if (char_verification(index->count_p, index->count_e, index->count_c))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	game_is_playable(t_list *map)
{
	t_list	init;
	t_int	init_data;
	int		y;

	init.index = &init_data;
	init.index->count_c = 0;
	init.index->count_e = 0;
	init.index->count_p = 0;
	y = 0;
	if (count_char(map, y, init.index))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	teste_columns(t_list *map)
{
	int	index_y;
	int	index_x;

	index_y = 0;
	while (index_y < map->y)
	{
		index_x = 0;
		if (map->matriz[index_y][0] != '1'
			|| map->matriz[index_y][map->x - 2] != '1')
			return (EXIT_FAILURE);
		while (index_x < map->x - 1)
		{
			if (map->matriz[0][index_x] != '1'
			|| map->matriz[map->y - 1][index_x] != '1')
				return (2);
			index_x++;
		}
		index_y++;
	}
	return (EXIT_SUCCESS);
}

int	init_teste(t_list *map)
{
	int	value;

	value = teste_columns(map);
	if (value == 1)
	{
		ft_printf("[ERROR] There is a column with an invalid\n");
		return (EXIT_FAILURE);
	}
	else if (value == 2)
	{
		ft_printf("[ERROR] The last line is invalid \n");
		return (EXIT_FAILURE);
	}
	if (game_is_playable(map))
	{
		ft_printf("[ERROR]: Map invalid!\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

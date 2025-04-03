/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:44:16 by alda-sil          #+#    #+#             */
/*   Updated: 2025/03/25 16:24:07 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(char **matriz, int hei, int wi, t_list **map)
{
	if (!(*map)->is_init)
	{
		if (matriz[hei][wi] != '0' && matriz[hei][wi] != 'E'
			&& matriz[hei][wi] != 'C')
			return ;
		if (matriz[hei][wi] == 'C')
			(*map)->copy_coin--;
		if (matriz[hei][wi] == 'E')
			(*map)->count_exit--;
	}
	matriz[hei][wi] = 'V';
	(*map)->is_init = 0;
	flood_fill(matriz, hei + 1, wi, map);
	flood_fill(matriz, hei - 1, wi, map);
	flood_fill(matriz, hei, wi + 1, map);
	flood_fill(matriz, hei, wi - 1, map);
}

char	**copy_matriz(t_list **map, int hei, int wi)
{
	char	**copy;
	int		index;
	int		index_2;

	index = 0;
	copy = (char **)ft_calloc((*map)->y, sizeof(char *));
	if (!copy)
		return (NULL);
	while (index < hei)
	{
		copy[index] = (char *)ft_calloc((*map)->x + 1, sizeof(char *));
		if (parsing_copy(copy, index))
			return (NULL);
		index_2 = 0;
		while (index_2 < wi)
		{
			copy[index][index_2] = (*map)->matriz[index][index_2];
			index_2++;
		}	
		copy[index][index_2] = '\0';
		index++;
	}
	return (copy);
}

int	init_flood(t_list *map)
{
	char	**copy_matriz_init;

	copy_matriz_init = copy_matriz(&map, map->y, map->x);
	if (copy_matriz_init == NULL)
		return (EXIT_FAILURE);
	find_player_and_count_coin(map);
	find_exit(map);
	map->copy_coin = map->size_coin;
	map->count_exit = 1;
	map->is_init = 1;
	flood_fill(copy_matriz_init, map->player_y, map->player_x, &map);
	if (map->copy_coin != 0 || map->count_exit != 0)
	{
		ft_printf("[ERROR]: invalid map\n");
		frees(copy_matriz_init, map->y);
		frees(map->matriz, map->y);
		return (EXIT_FAILURE);
	}
	frees(copy_matriz_init, map->y);
	return (EXIT_SUCCESS);
}

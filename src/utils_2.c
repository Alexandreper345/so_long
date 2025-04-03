/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 22:20:18 by alda-sil          #+#    #+#             */
/*   Updated: 2025/03/24 20:58:48 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_player_and_count_coin(t_list *map)
{
	int	index_y;
	int	index_x;
	int	count;

	index_y = 0;
	count = 0;
	while (index_y < map->y)
	{
		index_x = 0;
		while (index_x < map->x)
		{
			if (map->matriz[index_y][index_x] == 'P')
			{
				map->player_x = index_x;
				map->player_y = index_y;
			}
			if (map->matriz[index_y][index_x] == 'C')
				count++;
			index_x++;
		}
		index_y++;
	}
	map->size_coin = count;
}

void	find_exit(t_list *map)
{
	int	index_y;
	int	index_x;

	index_y = 0;
	while (index_y < map->y)
	{
		index_x = 0;
		while (index_x < map->x)
		{
			if (map->matriz[index_y][index_x] == 'E')
			{
				map->exit_x = index_x;
				map->exit_y = index_y;
			}
			index_x++;
		}
		index_y++;
	}
}

int	x_pressed(t_vars *vars)
{
	terminate(vars);
	return (EXIT_SUCCESS);
}

void	count_movies(int key, t_list *pos)
{
	if (key == 'a'
		&& pos->matriz[pos->player_y][pos->player_x - 1] != '1')
		pos->count_movies++;
	else if (key == 'd'
		&& pos->matriz[pos->player_y][pos->player_x + 1] != '1')
		pos->count_movies++;
	else if (key == 'w'
		&& pos->matriz[pos->player_y - 1][pos->player_x] != '1')
		pos->count_movies++;
	else if (key == 's'
		&& pos->matriz[pos->player_y + 1][pos->player_x] != '1')
		pos->count_movies++;
}

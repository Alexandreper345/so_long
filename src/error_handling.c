/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:59:11 by alda-sil          #+#    #+#             */
/*   Updated: 2025/03/25 18:59:31 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	frees(char **matriz, int height)
{
	int	index;

	index = 0;
	while (index < height)
	{
		free(matriz[index]);
		index++;
	}
	free(matriz);
}

void	free_map(t_list *map)
{
	int	index;

	index = 0;
	while (index < map->y + 1)
	{
		free(map->matriz[index]);
		index++;
	}
	free(map->matriz);
}

int	this_rectangular(char *line, int len)
{
	int	temp;

	temp = ft_strlen(line);
	if (line[temp - 1] != '\n')
		temp += 1;
	if (len != temp)
	{
		ft_printf("[Error] the size of the is different\n");
		return (1);
	}
	return (0);
}

int	parsing_copy(char **copy, int index)
{
	if (!copy[index])
	{
		while (index >= 0)
		{
			free(copy[index]);
			index--;
		}
		free(copy);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matriz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:15:03 by alda-sil          #+#    #+#             */
/*   Updated: 2025/03/24 21:11:11 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_matriz(t_list *map, char *map_path)
{
	int		fd;
	char	*line;
	int		index;
	int		flag;

	fd = open(map_path, O_RDWR);
	flag = 0;
	index = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (this_rectangular(line, map->x))
			flag = 1;
		ft_strlcpy(map->matriz[index], line, map->x);
		index++;
		free(line);
		line = get_next_line(fd);
	}
	if (flag)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	alloc(t_list *map, char *map_path)
{
	int	index;

	index = 0;
	while (index < map->y)
	{
		map->matriz[index] = ft_calloc(sizeof(char), map->x + 1);
		if (map->matriz[index] == NULL)
		{
			frees(map->matriz, map->y);
			return (EXIT_FAILURE);
		}
		index++;
	}
	if (init_matriz(map, map_path))
	{
		frees(map->matriz, map->y);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

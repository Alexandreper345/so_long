/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:43:25 by alda-sil          #+#    #+#             */
/*   Updated: 2025/02/25 21:12:10 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"

int	init_matrix(t_list *map, char *map_path)
{
	int		fd;
	char	*line;
	int 	i;
	size_t 	len;
	int 	flag;
	
	flag = 0;
	fd = open(map_path, O_RDWR);
	i = 0;
	if (fd_error(fd))
		return (1);
	line = get_next_line(fd);
	len = ft_strlen(line);
	while (line)
	{
		if (this_rectangular(line, len))
			flag = 1;
		ft_strlcpy(map->matrix[i], line, map->x);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	if (flag)
		return (1);
	return (0);
}

void	alloc(t_list *map)
{
	int		i;

	i = -1;
	while (i++ < map->y)
	{
		map->matrix[i] = calloc(sizeof(char), map->x + 1);
		if (map->matrix[i] == NULL)
		{
			frees(map->matrix, map->y);
			return ;
		}
	}
}

int	main(int argc, char **argv)
{
	t_list	map;
	size_t	len;

	if (argc != 2)
		return (0);
	len = 0;
	size_width(argv[1], &map);
	size_height(argv[1], &map);
	
	map.matrix = (char **)calloc(sizeof(char *), map.y + 1);
	
	if (!map.matrix)
		return (0);
	alloc(&map);
	if (init_matrix(&map, argv[1]))
	{
		frees(map.matrix, map.y);
		return (0);
	}
	frees(map.matrix, map.y);
	return (0);
}

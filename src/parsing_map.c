/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:19:06 by alda-sil          #+#    #+#             */
/*   Updated: 2025/03/25 19:53:07 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	format_file(char *map_path)
{
	char	*dot_pos;
	int		res;

	dot_pos = ft_strrchr(map_path, '.');
	if (!dot_pos)
	{
		ft_printf("[ERROR]: format invalid\n");
		return (EXIT_FAILURE);
	}
	res = ft_strcmp(dot_pos, ".ber");
	if (res != 0)
	{
		ft_printf("[ERROR]: format invalid\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	this_map_exists(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
	{
		ft_printf("[ERROR]: this map is NULL\n");
		return (EXIT_FAILURE);
	}
	if (line[0] == '\n')
	{
		ft_printf("[ERROR]: the first line is a line break\n");
		free(line);
		return (EXIT_FAILURE);
	}
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != '1')
		{
			ft_printf("[ERROR]: this map is invalid\n");
			free(line);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	count_caracter(char *line, char caracter)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == caracter)
			count++;
		i++;
	}
	return (count);
}

int	parsing_map(char *map_path)
{
	int		fd;
	char	*line;

	if (format_file(map_path))
		return (EXIT_FAILURE);
	fd = open(map_path, O_RDWR);
	if (fd == -1)
	{
		ft_printf("[ERROR]: fd failed\n");
		return (EXIT_FAILURE);
	}
	line = get_next_line(fd);
	if (this_map_exists(line))
		return (EXIT_FAILURE);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:18:19 by alda-sil          #+#    #+#             */
/*   Updated: 2025/02/25 19:25:02 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../long.h"

void	size_width(char	*map_path, t_list *map)
{
	int		fd;
	char	*line;
	size_t	len;

	fd = open(map_path, O_RDWR);
	if (fd_error(fd))
		return ;
	line = get_next_line(fd);
	len = ft_strlen(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map->x = len;
}

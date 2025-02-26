/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:18:04 by alda-sil          #+#    #+#             */
/*   Updated: 2025/02/25 18:11:10 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../long.h"

void	size_height(char *map_path, t_list *map)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(map_path, O_RDWR);
	if (fd_error(fd))
		return ;
	line = get_next_line(fd);
	count = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	close(fd);
	map->y = count;
}
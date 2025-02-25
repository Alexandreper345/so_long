/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:18:19 by alda-sil          #+#    #+#             */
/*   Updated: 2025/02/24 19:54:07 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../long.h"

int	size_width(char	*map_path)
{
	int		fd;
	char	*line;
	size_t	len;

	fd = open(map_path, O_RDWR);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	len = ft_strlen(line);
	while (line)
	{
		if (this_rectangular(line, len))
		{
			close(fd);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (len);
}

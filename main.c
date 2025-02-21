/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:43:25 by alda-sil          #+#    #+#             */
/*   Updated: 2025/02/20 21:35:10 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"

int	main(void)
{
	int i;
	int fd;
	size_t	len;
	char	*line;
	char	*line_backup;
	i = 1;
	fd = open("texto.txt", O_RDWR);
	if (fd == -1)
	{
		ft_printf("error");
		return (0);
	}
	line = get_next_line(fd);
	line_backup = ft_strdup(line);
	len = ft_strlen(line);
	if (this_rectangular(line, len, fd))
		return (0);
	line = line_backup;	
	while (line)
	{
		line = get_next_line(fd);
		ft_printf(line);
		free(line);
	}
	
	close(fd);
	return (0);
}

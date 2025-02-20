/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:43:25 by alda-sil          #+#    #+#             */
/*   Updated: 2025/02/19 20:50:28 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"

int	main(void)
{
	int i;
	int fd;
	size_t	len;
	char	*line;

	i = 1;
	fd = open("texto.txt", O_RDWR);
	if (fd == -1)
	{
		ft_printf("error");
		return (0);
	}
	line = get_next_line(fd);
	len = ft_strlen(line);
	while (line)
	{
		ft_printf(line);
		//if (this_rectangular(line))
		//	return (0);
		free(line);
		line = get_next_line(fd);
		if (line != NULL && len != ft_strlen(line))
		{
			ft_printf("Error");
			return (0);
		}
	}
	close(fd);
	return (0);
}

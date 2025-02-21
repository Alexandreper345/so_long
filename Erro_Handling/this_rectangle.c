/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:22:51 by alda-sil          #+#    #+#             */
/*   Updated: 2025/02/20 21:26:48 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../long.h"

void	free_both(char *line)
{
	if (*line)
	{
		free(line);
		line = NULL;
	}
}

int	this_rectangular(char *line, size_t len, int fd)
{
	size_t temp;
	
	while (line)
	{
		temp = ft_strlen(line);
		if (line[temp - 1] != '\n')
				temp += 1;	
		if (len != temp)
		{
			free_both(line);
			ft_printf("Error\n");
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

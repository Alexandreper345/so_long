/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:22:51 by alda-sil          #+#    #+#             */
/*   Updated: 2025/02/25 20:39:00 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../long.h"

void	free_both(char **line)
{
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
}

int	this_rectangular(char *line, size_t len)
{
	size_t temp;
	
	temp = ft_strlen(line);
	if (line[temp - 1] != '\n')
			temp += 1;	
	if (len != temp)
	{
		ft_printf("Error\n");
		//free_both(&line);
		return (1);
	}
	return (0);
}

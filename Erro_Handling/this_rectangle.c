/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:22:51 by alda-sil          #+#    #+#             */
/*   Updated: 2025/02/19 20:17:50 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../long.h"

int	this_rectangular(char *line)
{
	size_t temp;
	size_t i;

	i = 0;
	temp = ft_strlen(line);
	while (i < temp)
	{
		if (temp != ft_strlen(line))
			return (1);
		i++;
	}
	return (0);
}

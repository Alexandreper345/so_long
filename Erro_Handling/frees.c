/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:42:04 by alda-sil          #+#    #+#             */
/*   Updated: 2025/02/24 21:57:08 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../long.h"

void	frees(char **matrix, int height , int Width)
{
	int j;
	
	j = 0;
	while (j <  height + 1)
	{
		free(matrix[j]);
		j++;
	}
	free(matrix);
}
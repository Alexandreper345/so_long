/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:43:25 by alda-sil          #+#    #+#             */
/*   Updated: 2025/02/24 21:54:52 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"


char	**alloc(char **matrix, int height, int width)
{
	int		i;

	i = 0;
	while (i++ < height)
	{
		matrix[i] = calloc(sizeof(char), width + 1);
		if (matrix[i] == NULL)
		{
			frees(matrix, height, width);
			return (NULL);
		}
	}
	return (matrix);
}

int	main(int argc, char **argv)
{
	char	**matrix;
	size_t	len;
	int		len_height;
	int		len_width;

	if (argc != 2)
		return (0);
	len = 0;
	len_height = size_height(argv[1]);
	len_width = size_width(argv[1]);

	ft_printf("a altura {%d}, e a largura {%d}", len_height, len_width);
	matrix = (char **)calloc(sizeof(char *), len_height + 1);
	
	if (!matrix)
		return (0);
	alloc(matrix, len_height,len_width);	
	frees(matrix, len_height, len_width);
	return (0);
}

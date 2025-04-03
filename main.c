/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:25:58 by alda-sil          #+#    #+#             */
/*   Updated: 2025/03/25 16:13:24 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_list	map;

	if (argc != 2 || parsing_map(argv[1]))
		return (EXIT_FAILURE);
	size_wid_hei(argv[1], &map);
	map.matriz = (char **)ft_calloc(sizeof(char *), map.y + 1);
	if (!map.matriz)
		return (EXIT_FAILURE);
	if (alloc(&map, argv[1]))
		return (EXIT_FAILURE);
	if (init_teste(&map))
	{
		frees(map.matriz, map.y);
		return (EXIT_FAILURE);
	}
	if (init_flood(&map))
		return (EXIT_FAILURE);
	if (init_mini(&map))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

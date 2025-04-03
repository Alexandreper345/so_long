/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:16:37 by alda-sil          #+#    #+#             */
/*   Updated: 2025/03/24 20:54:03 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	load_img(t_list *t_list, t_vars vars, t_map *img)
{
	int	img_w;
	int	img_h;

	img->play = mlx_xpm_file_to_image(vars.mlx,
			"src/img/p/p1.xpm", &img_w, &img_h);
	img->coin = mlx_xpm_file_to_image(vars.mlx,
			"src/img/c/c6.xpm", &img_w, &img_h);
	img->wall = mlx_xpm_file_to_image(vars.mlx,
			"src/img/1/block.xpm", &img_w, &img_h);
	img->exit = mlx_xpm_file_to_image(vars.mlx,
			"src/img/e/e1.xpm", &img_w, &img_h);
	img->ground = mlx_xpm_file_to_image(vars.mlx,
			"src/img/preto.xpm", &img_w, &img_h);
	if (img->play == NULL || img->wall == NULL
		|| img->coin == NULL || img->exit == NULL
		|| img->ground == NULL)
		return (1);
	return (0);
}

void	draw(t_map *img, t_vars vars, t_list *list, t_int *integer)
{
	if (list->matriz[integer->index_y][integer->index_x] == '1')
		mlx_put_image_to_window(vars.mlx, vars.win, img->wall,
			integer->map_x, integer-> map_y);
	else if (list->matriz[integer->index_y][integer->index_x] == 'C')
		mlx_put_image_to_window(vars.mlx, vars.win,
			img->coin, integer->map_x, integer-> map_y);
	else if (list->matriz[integer->index_y][integer->index_x] == 'P')
		mlx_put_image_to_window(vars.mlx, vars.win,
			img->play, integer->map_x, integer-> map_y);
	else if (list->matriz[integer->index_y][integer->index_x] == 'E')
		mlx_put_image_to_window(vars.mlx, vars.win,
			img->exit, integer->map_x, integer-> map_y);
	else if (list->matriz[integer->index_y][integer->index_x] == '0')
		mlx_put_image_to_window(vars.mlx, vars.win,
			img->ground, integer->map_x, integer-> map_y);
}

int	xpm_file_image(t_map *img, t_vars vars, t_list *list)
{
	t_int	integer;

	integer.index_y = 0;
	integer.map_y = 0;
	while (integer.index_y < list->y)
	{
		integer.index_x = 0;
		integer.map_x = 0;
		while (integer.index_x < list->x)
		{
			draw(img, vars, list, &integer);
			integer.index_x++;
			integer.map_x += 72;
		}
		integer.index_y++;
		integer.map_y += 72;
	}
	return (0);
}

int	key_hook(int key_hook, t_vars *vars)
{	
	if (key_hook == 65307)
		terminate(vars);
	player_coin(key_hook, vars->position, vars);
	if (player_position(key_hook, vars->position, vars))
		return (EXIT_FAILURE);
	xpm_file_image(vars->stru, *vars, vars->position);
	return (EXIT_SUCCESS);
}

int	init_mini(t_list *map)
{
	t_vars	vars;
	t_map	maps;

	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (EXIT_FAILURE);
	vars.win = mlx_new_window(vars.mlx, 72 * (map->x - 1), 72 * map->y,
			"segmentation fault (core dumped)");
	if (vars.win == NULL)
	{
		free(vars.win);
		return (EXIT_FAILURE);
	}
	load_img(map, vars, &maps);
	vars.stru = &maps;
	vars.position = map;
	vars.position->count_movies = 0;
	if (xpm_file_image(&maps, vars, map))
		return (EXIT_FAILURE);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, x_pressed, &vars);
	mlx_loop(vars.mlx);
	return (EXIT_SUCCESS);
}

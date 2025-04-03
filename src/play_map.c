/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:34:29 by alda-sil          #+#    #+#             */
/*   Updated: 2025/03/24 20:57:30 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	terminate(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->stru->coin);
	mlx_destroy_image(vars->mlx, vars->stru->exit);
	mlx_destroy_image(vars->mlx, vars->stru->ground);
	mlx_destroy_image(vars->mlx, vars->stru->play);
	mlx_destroy_image(vars->mlx, vars->stru->wall);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	frees(vars->position->matriz, vars->position->y);
	exit(0);
}

int	exit_map(int key_hook, t_vars *vars, t_list *position)
{
	if (key_hook == 'a'
		&& position->matriz[position->player_y][position->player_x - 1] == 'E'
		&& position->size_coin == 0)
		terminate(vars);
	else if (key_hook == 'd'
		&& position->matriz[position->player_y][position->player_x + 1] == 'E'
		&& position->size_coin == 0)
		terminate(vars);
	else if (key_hook == 'w'
		&& position->matriz[position->player_y - 1][position->player_x] == 'E'
		&& position->size_coin == 0)
		terminate(vars);
	else if (key_hook == 's'
		&& position->matriz[position->player_y + 1][position->player_x] == 'E'
		&& position->size_coin == 0)
		terminate(vars);
	return (0);
}

void	codition_ifs(int key_hook, t_list *pos, t_vars *vars)
{
	exit_map(key_hook, vars, pos);
	count_movies(key_hook, pos);
	if (key_hook == 'a'
		&& pos->matriz[pos->player_y][pos->player_x - 1] != '1')
		pos->player_x--;
	else if (key_hook == 'd'
		&& pos->matriz[pos->player_y][pos->player_x + 1] != '1')
		pos->player_x++;
	else if (key_hook == 'w'
		&& pos->matriz[pos->player_y - 1][pos->player_x] != '1')
		pos->player_y--;
	else if (key_hook == 's'
		&& pos->matriz[pos->player_y + 1][pos->player_x] != '1')
		pos->player_y++;
	ft_printf("o seus movimentos atual é: %d\n", pos->count_movies);
}

int	player_position(int key_hook, t_list *position, t_vars *vars)
{
	position->matriz[position->player_y][position->player_x] = '0';
	codition_ifs(key_hook, position, vars);
	position->matriz[position->exit_y][position->exit_x] = 'E';
	position->matriz[position->player_y][position->player_x] = 'P';
	return (0);
}

int	player_coin(int key_hook, t_list *position, t_vars *vars)
{
	if (key_hook == 'a')
	{
		if (position->matriz[position->player_y][position->player_x - 1] == 'C')
			position->size_coin--;
	}
	else if (key_hook == 'd')
	{
		if (position->matriz[position->player_y][position->player_x + 1] == 'C')
			position->size_coin--;
	}
	else if (key_hook == 'w')
	{
		if (position->matriz[position->player_y - 1][position->player_x] == 'C')
			position->size_coin--;
	}
	else if (key_hook == 's')
	{
		if (position->matriz[position->player_y + 1][position->player_x] == 'C')
			position->size_coin--;
	}
	ft_printf("o total que você tem de coin é: %d\n", position->size_coin);
	return (position->size_coin);
}

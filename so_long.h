/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:50:02 by alda-sil          #+#    #+#             */
/*   Updated: 2025/03/24 20:47:51 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Get_next_line/get_next_line.h"
# include "Printf/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>

typedef struct so_int
{
	int	index_x;
	int	index_y;
	int	map_x;
	int	map_y;
	int	inter_coin;
	int	count_movies;
	int	count_p;
	int	count_e;
	int	count_c;
}	t_int;

typedef struct s_list
{
	char	**matriz;
	int		x;
	int		y;
	int		player_x;
	int		player_y;
	int		size_coin;
	int		count_movies;
	int		exit_x;
	int		exit_y;
	int		copy_coin;
	int		count_exit;
	int		is_init;
	t_int	*index;
}	t_list;

typedef struct so_map
{
	void	*play;
	void	*coin;
	void	*exit;
	void	*wall;
	void	*ground;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	t_list	*position;
	t_map	*stru;
}	t_vars;

void	frees(char **matriz, int height);
void	free_map(t_list *map);
void	size_wid_hei(char *map_path, t_list *map);
void	*ft_calloc(size_t nmemb, size_t size);
void	find_exit(t_list *map);
void	terminate(t_vars *vars);
void	find_player_and_count_coin(t_list *map);
void	count_movies(int key, t_list *pos);
int		player_position(int key_hook, t_list *position, t_vars *vars);
int		exit_map(int key_hook, t_vars *vars, t_list *position);
int		x_pressed(t_vars *vars);
int		init_mini(t_list *map);
int		player_coin(int key_hook, t_list *position, t_vars *vars);
int		init_matriz(t_list *map, char *map_path);
int		this_rectangular(char *line, int len);
int		parsing_map(char *map_path);
int		ft_strcmp(const char *s1, const char *s2);
int		alloc(t_list *map, char *map_path);
int		init_flood(t_list *map);
int		parsing_copy(char **copy, int index);
int		init_teste(t_list *map);
int		map_invalid(t_list *map, int x, int y);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strrchr(const char *s, int c);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:02:34 by alda-sil          #+#    #+#             */
/*   Updated: 2025/02/25 20:05:58 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LONG_H
# define LONG_H
# include "Get_next_line/get_next_line.h"
# include "Printf/ft_printf.h"
# include <fcntl.h>

typedef struct s_list
{
	char **matrix;
	int		x;
	int		y;
	
} t_list;

int		fd_error(int fd);
int		this_rectangular(char *line, size_t len);
void	size_height(char *map_path, t_list *map);
void	size_width(char	*map_path, t_list *map);
void	frees(char **matrix, int height);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
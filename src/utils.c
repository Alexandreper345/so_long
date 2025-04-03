/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:12:27 by alda-sil          #+#    #+#             */
/*   Updated: 2025/03/24 20:58:04 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	i = ft_strlen(src);
	if (size == 0)
		return (ft_strlen(src));
	while (src[j] && j < size - 1)
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

void	size_wid_hei(char *map_path, t_list *map)
{
	int		count_hei;
	size_t	count_wid;
	int		fd;
	char	*line;

	count_hei = 0;
	fd = open(map_path, O_RDWR);
	line = get_next_line(fd);
	count_wid = ft_strlen(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		count_hei++;
	}
	close(fd);
	map->x = count_wid;
	map->y = count_hei;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*str;
	size_t		full_size;
	size_t		i;

	i = 0;
	full_size = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (full_size / nmemb != size)
		return (NULL);
	str = malloc(full_size);
	if (!str)
		return (NULL);
	while (i < full_size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

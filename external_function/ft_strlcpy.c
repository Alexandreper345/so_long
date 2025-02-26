/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:35:52 by alda-sil          #+#    #+#             */
/*   Updated: 2025/02/25 18:31:03 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../long.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	i = ft_strlen(src);
	if (size == 0)
		return (ft_strlen(src));
	while (src[j] && src[j] != '\n' && j < size - 1)
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}
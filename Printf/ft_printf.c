/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:33:52 by alda-sil          #+#    #+#             */
/*   Updated: 2025/02/19 18:21:26 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	verfication(const char *s, va_list list)
{
	int	count;

	count = 0;
	if (*s == 's')
		count += ft_putstr(va_arg(list, char *));
	else if (*s == 'c')
		count += ft_putchar((char)va_arg(list, int));
	else if (*s == 'd' || *s == 'i')
		count += ft_putnbr("0123456789", va_arg(list, int));
	else if (*s == 'X')
		count += ft_hexa("0123456789ABCDEF", va_arg(list, unsigned int));
	else if (*s == 'x')
		count += ft_hexa("0123456789abcdef", va_arg(list, unsigned int));
	else if (*s == 'u')
		count += ft_putnbunsi(va_arg(list, unsigned int));
	else if (*s == 'p')
		count += ft_voidpoint(va_arg(list, void *));
	else if (*s == '%')
		count += ft_putchar(*s);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		count;

	if (!s)
		return (-1);
	count = 0;
	va_start(list, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			count += verfication(s, list);
		}
		else
			count += ft_putchar(*s);
		s++;
	}
	va_end(list);
	return (count);
}

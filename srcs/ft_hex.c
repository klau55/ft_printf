/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:08:21 by nkarpilo          #+#    #+#             */
/*   Updated: 2023/11/20 15:29:14 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char_cpy(char *dest, char src, int *pos)
{
	dest[(*pos)++] = src;
}

int	ft_hex_len(unsigned int nb)
{
	int	i;

	i = 1;
	while (nb >= 16)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

void	ft_puthex(char *str, unsigned int nb, int *pos, char format)
{
	const char	*charset;

	if (format == 'X')
		charset = "0123456789ABCDEF";
	else
		charset = "0123456789abcdef";
	if (nb < 16)
		ft_char_cpy(str, charset[nb], pos);
	else
	{
		ft_puthex(str, nb / 16, pos, format);
		ft_char_cpy(str, charset[nb % 16], pos);
	}
}

int	ft_print_hex(unsigned int n, int total, const char format, va_list args)
{
	char	*str;
	int		len;
	int		pos;

	len = ft_hex_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (-1);
	pos = 0;
	ft_puthex(str, n, &pos, format);
	str[pos] = '\0';
	if (ft_print_str(str, total, args) < 0)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (len);
}

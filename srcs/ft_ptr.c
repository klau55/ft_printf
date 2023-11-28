/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:08:53 by nkarpilo          #+#    #+#             */
/*   Updated: 2023/11/28 17:29:32 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_long_len(unsigned long long nb)
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

void	ft_char_cpy(char *dest, char src, int *pos)
{
	dest[(*pos)++] = src;
}

void	ft_ptr_puthex(char *str, unsigned long long nb, int *pos)
{
	const char	*charset;

	charset = "0123456789abcdef";
	if (nb < 16)
		ft_char_cpy(str, charset[nb], pos);
	else
	{
		ft_ptr_puthex(str, nb / 16, pos);
		ft_char_cpy(str, charset[nb % 16], pos);
	}
}

int	ft_print_ptr(void *ptr)
{
	unsigned long long int	ptr_val;
	char					*str;
	int						len;
	int						pos;

	ptr_val = (unsigned long long)ptr;
	len = ft_hex_long_len(ptr_val);
	str = (char *)malloc((len + 3) * sizeof(char));
	if (!str)
		return (-1);
	str[0] = '0';
	str[1] = 'x';
	pos = 2;
	ft_ptr_puthex(str, ptr_val, &pos);
	str[pos] = '\0';
	if (ft_print_str(str) < 0)
	{
		free(str);
		return (-1);
	}
	free (str);
	return (len + 2);
}

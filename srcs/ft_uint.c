/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:55:54 by nkarpilo          #+#    #+#             */
/*   Updated: 2023/11/20 16:30:33 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uint_num_len(unsigned int n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_uint_to_str(char *str, unsigned int n, int *pos)
{
	if (n < 10)
		ft_char_cpy(str, (n + '0'), pos);
	else
	{
		ft_uint_to_str(str, (n / 10), pos);
		ft_char_cpy(str, ((n % 10) + '0'), pos);
	}
}

int	ft_print_uint(unsigned int n, va_list args)
{
	char	*str;
	int		pos;
	int		len;

	len = ft_uint_num_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (-1);
	pos = 0;
	ft_uint_to_str(str, n, &pos);
	str[pos] = '\0';
	if (ft_print_str(str, 1, args) < 0)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (len);
}

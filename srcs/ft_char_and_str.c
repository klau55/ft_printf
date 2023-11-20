/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_and_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:08:53 by nkarpilo          #+#    #+#             */
/*   Updated: 2023/11/20 17:09:40 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *s, va_list args)
{
	int	len;

	len = 0;
	if (s == NULL)
	{
		if (ft_print_str("(null)", args) < 0)
		{
			va_end(args);
			return (-1);
		}
		return (6);
	}
	while (*s)
	{
		if (ft_print_char(*s++) < 0)
		{
			va_end(args);
			return (-1);
		}
		len++;
	}
	return (len);
}

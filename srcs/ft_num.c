/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:02:52 by nkarpilo          #+#    #+#             */
/*   Updated: 2023/11/20 17:06:14 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_num(int d, int total)
{
	if (d == -2147483648)
	{
		write (1, "-2147483648", 11);
		total = total + 11;
	}
	else if (d < 0)
	{
		total += ft_print_char('-');
		total = ft_print_num(-d, total);
	}
	else if (d >= 0 && d < 10)
		total += ft_print_char(d + '0');
	else
	{
		total = ft_print_num(d / 10, total);
		total += ft_print_char(d % 10 + '0');
	}
	return (total);
}

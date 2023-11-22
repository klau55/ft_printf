/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:02:52 by nkarpilo          #+#    #+#             */
/*   Updated: 2023/11/22 18:58:02 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_negative(int d, int total)
{
	total += ft_print_char('-');
	if (!total || total < 0)
		return (-1);
	total = ft_print_num(-d, total);
	if (!total || total < 0)
		return (-1);
	return (total);
}

int	ft_print_num(int d, int total)
{
	if (d == -2147483648)
	{
		if (ft_print_str("-2147483648", 0) < 0)
			return (-1);
		total = total + 11;
	}
	else if (d < 0)
		return (ft_print_negative(d, total));
	else if (d >= 0 && d < 10)
	{
		if (ft_print_char(d + '0') < 0)
			return (-1);
		++total;
	}
	else
	{
		total = ft_print_num(d / 10, total);
		if (!total || total < 0)
			return (-1);
		if (ft_print_char((d % 10) + '0') < 0)
			return (-1);
		++total;
	}
	return (total);
}

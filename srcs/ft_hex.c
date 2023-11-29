/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:08:21 by nkarpilo          #+#    #+#             */
/*   Updated: 2023/11/29 17:19:35 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long n, const char format)
{
	int			count;
	const char	*base;
	int			error;

	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count = ft_print_hex(n / 16, format);
	if (count == -1)
		return (-1);
	error = write (1, &base[n % 16], 1);
	if (error == -1)
		return (-1);
	return (count + 1);
}

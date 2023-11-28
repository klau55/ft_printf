/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:55:54 by nkarpilo          #+#    #+#             */
/*   Updated: 2023/11/28 15:44:40 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint(unsigned int n)
{
	int			count;
	const char	*base;
	int			error;

	base = "0123456789";
	count = 0;
	if (n >= 10)
		count = ft_print_uint (n / 10);
	if (count == -1)
		return (-1);
	error = write (1, &base[n % 10], 1);
	if (error == -1)
		return (-1);
	return (count + 1);
}

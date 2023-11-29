/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:08:53 by nkarpilo          #+#    #+#             */
/*   Updated: 2023/11/29 17:39:31 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr, int total)
{
	int	add;

	add = write (1, "0x", 2);
	if (add < 0)
		return (-1);
	total = (add + ft_print_hex((unsigned long)ptr, 0, total));
	if (total < 0)
		return (-1);
	return (total);
}

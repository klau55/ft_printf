/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:08:53 by nkarpilo          #+#    #+#             */
/*   Updated: 2023/11/29 17:22:29 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	int	count;
	int	add;

	count = 0;
	add = write (1, "0x", 2);
	if (add == -1)
		return (-1);
	count = (add + ft_print_hex((unsigned long)ptr, 0));
	if (count == -1)
		return (-1);
	return (count);
}

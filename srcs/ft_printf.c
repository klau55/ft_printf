/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:37:30 by nkarpilo          #+#    #+#             */
/*   Updated: 2023/11/28 16:56:48 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_set_format(va_list args, const char format)
{
	if (format == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (format == 'd' || format == 'i')
		return (ft_print_num(va_arg(args, int), 0));
	else if (format == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (format == '%')
		return (ft_print_char('%'));
	else if (format == 'x' || format == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), format));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	else if (format == 'u')
		return (ft_print_uint(va_arg(args, unsigned int)));
	return (-1);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s != '\0')
		s++;
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total;
	int		temp;

	i = -1;
	total = 0;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%' && ft_strchr("udcspixX%", format[i + 1]))
		{
			temp = ft_set_format(args, format[++i]);
			if (temp < 0)
			{
				va_end(args);
				return (-1);
			}
			total += temp;
		}
		else if (ft_print_char(format[i]) >= 0)
			++total;
		else
			return (-1);
	}
	va_end(args);
	return (total);
}

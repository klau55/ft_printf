/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:37:30 by nkarpilo          #+#    #+#             */
/*   Updated: 2023/11/20 16:16:54 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c, int total)
{
	write(1, &c, 1);
	return (++total);
}

int	ft_print_str(char *s, int total, va_list args)
{
	int	len;

	len = 0;
	if (s == NULL)
	{
		if (ft_print_str("(null)", total, args) < 0)
		{
			va_end(args);
			return (-1);
		}
		return (6);
	}
	while (*s)
	{
		if (ft_print_char(*s++, total) < 0)
		{
			va_end(args);
			return (-1);
		}
		len++;
	}
	return (len);
}

int	ft_print_num(int d, int total)
{
	if (d == -2147483648)
	{
		write (1, "-2147483648", 11);
		total = total + 11;
	}
	else if (d < 0)
	{
		total = ft_print_char('-', total);
		total = ft_print_num(-d, total);
	}
	else if (d >= 0 && d < 10)
		total = ft_print_char(d + '0', total);
	else
	{
		total = ft_print_num(d / 10, total);
		total = ft_print_char(d % 10 + '0', total);
	}
	return (total);
}

int	ft_set_format(va_list args, const char format, int total)
{
	if (format == 'c')
		total = ft_print_char(va_arg(args, int), total);
	else if (format == 'd' || format == 'i')
		total = ft_print_num(va_arg(args, int), total);
	else if (format == 's')
		total += ft_print_str(va_arg(args, char *), total, args);
	else if (format == '%')
		total = ft_print_char('%', total);
	else if (format == 'x' || format == 'X')
		total += ft_print_hex(va_arg(args, int), total, format, args);
	else if (format == 'p')
		total += ft_print_ptr(va_arg(args, void *), args);
	else if (format == 'u')
		total = ft_print_uint(va_arg(args, unsigned int), args);
	return (total);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total;

	i = -1;
	total = 0;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if (strchr("udcspixX%%", format[i + 1]))
				total = ft_set_format(args, format[++i], total);
		}
		else
			total = ft_print_char(format[i], total);
	}
	va_end(args);
	return (total);
}

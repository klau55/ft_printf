/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:37:30 by nkarpilo          #+#    #+#             */
/*   Updated: 2023/11/15 19:38:20 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int	ft_printf_write(int c, int total)
{
	total++;
	write(1, &c, 1);
	return (total);
}

void	ft_print_char(int c, int total)
{
	ft_printf_write(c, total);
}

int	ft_print_str(char *s, int total,va_list args)
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
		if (ft_printf_write(*s++, total) < 0)
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
		total = ft_printf_write('-', total);
		total = ft_print_num(-d, total);
	}
	else if (d >= 0 && d < 10)
		total = ft_printf_write(d + '0', total);
	else
	{
		total = ft_print_num(d / 10, total);
		total = ft_printf_write(d % 10 + '0', total);
	}
	return (total);
}

int	ft_set_format(va_list args, const char format, int total)
{
	if (format == 'c')
		ft_print_char(va_arg(args, int), total);
	else if (format == 'd' || format == 'i')
		ft_print_num(va_arg(args, int), total);
	else if (format == 's')
		ft_print_str(va_arg(args, char *), total, args);
	else if (format == '%')
		ft_print_char('%', total);
	return (total);
}



int	ft_set_option(va_list args, const char format, int total)
{
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
			else if (strchr("#-+ .*0123456789hLljz", format[i + 1]))
				total = ft_set_option(args, format[++i], total);
		}
		else
			total = ft_printf_write(format[i], total);
	}
	va_end(args);
	return (total);
}

int	main(void)
{
	int	i;

	i = printf("hi\n");
	printf("i: %i\n", i);
	ft_printf("MIN number: %i**\n", INT32_MIN);
	printf("MIN number: %i***\n", INT32_MIN);
	i = ft_printf("me   --> hello 42!\n \
	c: %c, d: %d, s: %s i: %i\n" , 'z', 42, "ass", 484);
	printf("i: %i\n\n", i);
	return (0);
}

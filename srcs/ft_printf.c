/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:37:30 by nkarpilo          #+#    #+#             */
/*   Updated: 2023/11/17 17:57:42 by nkarpilo         ###   ########.fr       */
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

void	ft_char_cpy(char *dest, char src, int *pos)
{
	dest[(*pos)++] = src;
}

int	ft_hex_len(unsigned int nb)
{
	int	i;

	i = 1;
	while (nb >= 16)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

void 	ft_puthex(char *str, unsigned int nb, int *pos, char format)
{
	const char	*charset;

	if (format == 'X')
		charset = "0123456789ABCDEF";
	else
		charset = "0123456789abcdef";
	if (nb < 16)
		ft_char_cpy(str, charset[nb], pos);
	else
	{
		ft_puthex(str, nb / 16, pos, format);
		ft_char_cpy(str, charset[nb % 16], pos);
	}
}

int	ft_print_hex(unsigned int n, int total, const char format, va_list args)
{
	char	*str;
	int		len;
	int		pos;

	len = ft_hex_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (-1);
	pos = 0;
	ft_puthex(str, n, &pos, format);
	str[pos] = '\0';
	if (ft_print_str(str, total, args) < 0)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (len);
}

int	ft_hex_long_len(unsigned long long nb)
{
	int	i;

	i = 1;
	while (nb >= 16)
	{
		nb /= 16;
		i++;
	}
	return (i);
}


void	ft_ptr_puthex(char *str, unsigned long long nb, int *pos)
{
	const char	*charset;

	charset = "0123456789abcdef";
	if (nb < 16)
		ft_char_cpy(str, charset[nb], pos);
	else
	{
		ft_ptr_puthex(str, nb / 16, pos);
		ft_char_cpy(str, charset[nb % 16], pos);
	}
}

int	ft_print_ptr(void *ptr, va_list args, int total)
{
	unsigned long long int	ptr_val;
	char					*str;
	int						len;
	int						pos;

	ptr_val = (unsigned long long)ptr;
	len = ft_hex_long_len(ptr_val);
	str = (char *)malloc((len + 3) * sizeof(char));
	if (!str)
		return (-1);
	str[0] = '0';
	str[1] = '1';
	pos = 0;
	ft_ptr_puthex(str, ptr_val, &pos);
	str[pos] = '\0';
	if (ft_print_str(str, 1, args) < 0)
	{
		free(str);
		return (-1);
	}
	free (str);
	total = total + (len + 2);
	return (total);
}

int	ft_set_format(va_list args, const char format, int total)
{
	if (format == 'c')
		total = ft_print_char(va_arg(args, int), total);
	else if (format == 'd' || format == 'i')
		total = ft_print_num(va_arg(args, int), total);
	else if (format == 's')
		ft_print_str(va_arg(args, char *), total, args);
	else if (format == '%')
		ft_print_char('%', total);
	else if (format == 'x' || format == 'X')
		ft_print_hex(va_arg(args, int), total, format, args);
	else if (format == 'p')
		total = ft_print_ptr(va_arg(args, void *), args, total);
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

int	main(void)
{
	int	i;
	int	j;

	i = printf("hi\n");
	printf("i: %i\n", i);
	ft_printf("MIN number: %i**\n", INT32_MIN);
	printf("MIN number: %i***\n", INT32_MIN);
	i = ft_printf("me   --> hello 42 !\n \
	x: %x X: %X c: %c, d: %d, s: %s i: %i p: %p\n", \
	420, 420, 'z', 42, "ass", 48488, "48");
	j = printf("me   --> hello 42 !\n \
	x: %x X: %X c: %c, d: %d, s: %s i: %i p: %p\n", \
	420, 420, 'z', 42, "ass", 48488, "48");
	printf("i: %i j: %i\n\n", i, j);
	return (0);
}

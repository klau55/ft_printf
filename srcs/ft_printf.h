/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:08:40 by nkarpilo          #+#    #+#             */
/*   Updated: 2023/11/29 17:22:34 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_processor(va_list args, const char *format);
int		ft_set_format(va_list args, const char format);
int		ft_print_negative(int d, int total);
int		ft_print_num(int d, int total);
int		ft_print_char(int c);
int		ft_print_str(char *s);
int		ft_print_hex(unsigned long n, const char format);
int		ft_print_uint(unsigned int n);
int		ft_print_ptr(void *ptr);

#endif
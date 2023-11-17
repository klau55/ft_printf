#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>

int ft_print_char(int c, int total);
int	ft_print_str(char *s, int total, va_list args);
int	ft_print_num(int d, int total);
int	ft_set_format(va_list args, const char format, int total);
int	ft_set_option(va_list args, const char format, int total);
int	ft_printf(const char *format, ...);
int	main(void);

#endif
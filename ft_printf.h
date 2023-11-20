#ifndef LIBFT_H
# define LIBFT_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int ft_putchar(char c);
int ft_putstr(char *str);
int	ft_putnbr(int nb);
int ft_parse_conversions(char conv_sign, va_list args);
int ft_printf(const char *str, ...);

#endif
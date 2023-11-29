/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glabaden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:33:58 by glabaden          #+#    #+#             */
/*   Updated: 2023/11/24 15:34:01 by glabaden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_uputnbr(unsigned int nb);
int		ft_parse_conversions(char conv_sign, va_list args);
int		ft_printf(const char *str, ...);
int		handle_ptr(void *nb);
int		ft_hex_len(unsigned int num);
void	ft_lower_putnbr(unsigned int nb);
void	ft_upper_putnbr(unsigned int nb);
int		handle_lower_hex(unsigned int nb);
int		handle_upper_hex(unsigned int nb);

#endif

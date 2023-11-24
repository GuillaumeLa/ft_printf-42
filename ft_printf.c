/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glabaden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:50:36 by glabaden          #+#    #+#             */
/*   Updated: 2023/11/20 08:50:38 by glabaden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_parse_conversions(char conv_sign, va_list args)
{
	int	char_count;

	char_count = 0;
	if (conv_sign == 'c')
		char_count += ft_putchar((char)va_arg(args, int));
	else if (conv_sign == 's')
		char_count += ft_putstr((char *)va_arg(args, char *));
	else if (conv_sign == 'p')
		char_count += handle_ptr(va_arg(args, void *));
	else if (conv_sign == 'd')
		char_count += ft_putnbr(va_arg(args, int));
	else if (conv_sign == 'i')
		char_count += ft_putnbr(va_arg(args, int));
	else if (conv_sign == 'u')
		char_count += ft_uputnbr(va_arg(args, unsigned int));
	else if (conv_sign == 'x')
		char_count += handle_lower_hex(va_arg(args, unsigned int));
	else if (conv_sign == 'X')
		char_count += handle_upper_hex(va_arg(args, unsigned int));
	else if (conv_sign == '%')
		char_count += ft_putchar('%');
	return (char_count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		char_count;
	va_list	va;

	va_start(va, str);
	char_count = 0;
	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			char_count += ft_parse_conversions(str[i + 1], va);
			i++;
		}
		else
			char_count += ft_putchar(str[i]);
		i++;
	}
	return (char_count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilshexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glabaden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:30:46 by glabaden          #+#    #+#             */
/*   Updated: 2023/11/24 15:30:48 by glabaden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_lower_putnbr(unsigned int nb)
{
	if (nb >= 16)
	{
		ft_lower_putnbr(nb / 16);
		ft_lower_putnbr(nb % 16);
	}
	else
	{
		if (nb <= 9)
		{
			ft_putchar((nb + '0'));
		}
		else
		{
			ft_putchar((nb - 10 + 'a'));
		}
	}
}

void	ft_upper_putnbr(unsigned int nb)
{
	if (nb >= 16)
	{
		ft_upper_putnbr(nb / 16);
		ft_upper_putnbr(nb % 16);
	}
	else
	{
		if (nb <= 9)
		{
			ft_putchar((nb + '0'));
		}
		else
		{
			ft_putchar((nb - 10 + 'A'));
		}
	}
}

int	handle_lower_hex(unsigned int nb)
{
	if (!nb)
		return (ft_putchar('0'));
	ft_lower_putnbr(nb);
	return (ft_hex_len(nb));
}

int	handle_upper_hex(unsigned int nb)
{
	if (!nb)
		return (ft_putchar('0'));
	ft_upper_putnbr(nb);
	return (ft_hex_len(nb));
}

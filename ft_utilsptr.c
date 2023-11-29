/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilsptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glabaden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:04:48 by glabaden          #+#    #+#             */
/*   Updated: 2023/11/24 15:04:51 by glabaden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned long long num)
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

static void	ft_ptrputnbr(unsigned long long nb)
{
	if (nb >= 16)
	{
		ft_ptrputnbr(nb / 16);
		ft_ptrputnbr(nb % 16);
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

int	handle_ptr(void *nb)
{
	if (!nb)
		return (write(1, "(nil)", 5), 5);
	write(1, "0x", 2);
	ft_ptrputnbr((unsigned long long)nb);
	return (2 + ft_ptr_len(((unsigned long long)nb)));
}

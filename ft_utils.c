/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glabaden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:31:01 by glabaden          #+#    #+#             */
/*   Updated: 2023/11/24 15:31:06 by glabaden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"), 6);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	a;
	int	b;
	int	count;

	a = nb % 10;
	b = nb / 10;
	count = 0;
	if (b)
	{
		count = ft_putnbr(b);
	}
	if (nb < 0)
	{
		if (!b)
		{
			write(1, "-", 1);
			count++;
		}
		a = -a;
	}
	ft_putchar(a + '0');
	count++;
	return (count);
}

int	ft_uputnbr(unsigned int nb)
{
	unsigned int	a;
	unsigned int	b;
	int				count;

	a = nb % 10;
	b = nb / 10;
	count = 0;
	if (b)
	{
		count = ft_putnbr(b);
	}
	if (nb < 0)
	{
		if (!b)
		{
			write(1, "-", 1);
			count++;
		}
		a = -a;
	}
	ft_putchar(a + '0');
	count++;
	return (count);
}

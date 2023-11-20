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

#include "ft_printf.h"

int ft_putchar(char c)
{
    write(1,&c,1);
    return (1);
}
int ft_putstr(char *str)
{
    int i = 0;
    if(!str)
        return (0);
    while(str[i])
    {
        write(1,&str[i],1);
        i++;
    }

    return (i);
}
int	ft_putnbr(int nb)
{
	int	a;
	int	b;
    int count;

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
                write(1,"-",1);
                count++;
            }
            a = -a;
	}
	ft_putchar(a + '0');
    count++;
    return(count);
}
int	ft_uputnbr(int nb)
{
	int	a;
	int	b;
    int count;

	a = nb % 10;
	b = nb / 10;
    count = 0;
	if (b)
    {
		count = ft_putnbr(b);
    }
	if (nb < 0)
	{
        return(0);
	}
	ft_putchar(a + '0');
    count++;
    return(count);
}

int ft_parse_conversions(char conv_sign, va_list args)
{
    int char_count;

    char_count = 0; 
    if(conv_sign == 'c')
        char_count += ft_putchar((char)va_arg(args,int));
    else if(conv_sign == 's')
        char_count += ft_putstr((char *)va_arg(args,char *));
    // else if(conv_sign == 'p')
    else if(conv_sign == 'd')
        char_count += ft_putnbr((int)va_arg(args,int));
    else if(conv_sign == 'i')
        char_count += ft_putnbr((int)va_arg(args,int));
    else if(conv_sign == 'u')
        char_count += ft_uputnbr((unsigned int)va_arg(args,unsigned int));
    // else if(conv_sign == 'x')
        //ft_putnbr_base((int)va_arg(args,int),"123456789abcdef");
    // else if(conv_sign == 'X')
    else if(conv_sign == '%')
        write(1,"%",1);
    return (char_count);

}


int ft_printf(const char *str, ...)
{
    int i;
    int char_count;
    va_list va;
    va_start (va, str);
    
    char_count = 0;
    i = 0;
    while(str[i])
    {
        if(str[i] == '%')
        {  
            char_count +=  ft_parse_conversions(str[i+1],va);
            i++;
        }
        else
            char_count += ft_putchar(str[i]);
        i++;
    }
    return(char_count);
}
int main()
{
    int carotte = 4565456;
    ft_printf("%u \n",carotte);
    printf("%u", carotte);
    return(0);
}

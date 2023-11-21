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
//unsigned long long 
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
        return (ft_putstr("(null)"),6);
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
int	ft_uputnbr(unsigned int nb)
{
	unsigned int	a;
	unsigned int	b;
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
int    ft_hex_len(unsigned    int num)
{
    int    len;

    len = 0;
    while (num != 0)
    {
        len++;
        num = num / 16;
    }
    return (len);
}

void	ft_xputnbr(unsigned int nb)
{
    if (nb >= 16)
    {
        ft_xputnbr(nb / 16);
        ft_xputnbr(nb % 16);
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

void	ft_Xputnbr(unsigned int nb)
{
    if (nb >= 16)
    {
        ft_Xputnbr(nb / 16);
        ft_Xputnbr(nb % 16);
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

int try(unsigned int nb)
{
    if(!nb)
        return(ft_putchar('0'));
    ft_xputnbr(nb);
    return(ft_hex_len(nb));
}
int try_ptr(void *nb)
{
    if(!nb)
        return(write(1,"(nil)",5),5);
    write(1,"0x",2);
    ft_xputnbr((long unsigned int)nb);
    return(2 + ft_hex_len(((long unsigned int)nb)));

}
int trytwo(unsigned int nb)
{
    if(!nb)
        return(ft_putchar('0'));
    ft_Xputnbr(nb);
    return(ft_hex_len(nb));
}


int ft_parse_conversions(char conv_sign, va_list args)
{
    int char_count;

    char_count = 0; 
    if(conv_sign == 'c')
        char_count += ft_putchar((char)va_arg(args,int));
    else if(conv_sign == 's')
        char_count += ft_putstr((char *)va_arg(args,char *));
    else if(conv_sign == 'p')
    {
        char_count += try_ptr(va_arg(args,void *));

    }
    else if(conv_sign == 'd')
        char_count += ft_putnbr(va_arg(args,int));
    else if(conv_sign == 'i')
        char_count += ft_putnbr(va_arg(args,int));
    else if(conv_sign == 'u')
        char_count += ft_uputnbr(va_arg(args,unsigned int));
    else if(conv_sign == 'x')
        char_count += try(va_arg(args,unsigned int));
    else if(conv_sign == 'X')
        char_count += trytwo(va_arg(args,unsigned int));
    else if(conv_sign == '%')
        char_count += ft_putchar('%');
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
// int main()
// {
//     char *lol = "lol";
//     ft_printf("%5");

//     return(0);
// }

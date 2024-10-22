/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:25:11 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/22 18:02:50 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int ft_putnbr_base_low(int num)
{
	char *base = "0123456789abcdef"; 
	if (num == -2147483648)
	{
		ft_strlen("-7FFFFFFF");
		return (9);
	}
	if (num < 0)
	{
		ft_putchar('-');
		return(1 + ft_putnbr_base_low(num * -1));
	}
	else if (num > 15)
	{
		return (ft_putnbr_base_low(num / 16) + ft_putnbr_base_low(num % 16));
	}
	else
	{
		ft_putchar(base[num]);
		return (1);
	}
}

int ft_putnbr_base_maj(int num)
{
	char *base = "0123456789ABCDEF"; 
	if (num == -2147483648)
	{
		ft_strlen("-7FFFFFFF");
		return (9);
	}
	if (num < 0)
	{
		ft_putchar('-');
		return(1 + ft_putnbr_base_maj(num * -1));
	}
	else if (num > 15)
	{
		return (ft_putnbr_base_maj(num / 16) + ft_putnbr_base_maj(num % 16));
	}
	else
	{
		ft_putchar(base[num]);
		return (1);
	}
}



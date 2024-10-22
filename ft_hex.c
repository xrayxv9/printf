// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ft_hex.c                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2024/10/23 00:20:34 by xray              #+#    #+#             //
//   Updated: 2024/10/23 00:36:47 by xray             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include "ft_printf.h"

int	gen_hex(char *base, int num)
{
	if (num == -2147483648)
	{
		ft_putstr("-7FFFFFFF");
		return (9);
	}
	if (num < 0)
	{
		ft_putchar("-");
		return(1 + gen_hex(base, num * -1));
	}
	else if (num > 15)
	{
		return (gen_hex(base, num / 16) + gen_hex(base, num % 16));
	}
	else
	{
		ft_putchar(&base[num]);
		return (1);
	}
}

int ft_hexLow(void *i)
{
	int		*num;

	num = (int *)i;
	char *base = "0123456789abcdef"; 
	return (gen_hex(base, *num));
}

int ft_hexUp(void *i)
{
	int		*num;

	num = (int *)i;
	char *base = "0123456789ABCDEF"; 
	return (gen_hex(base, *num));
}

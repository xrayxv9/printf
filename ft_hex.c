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

int	gen_hex(char *base, unsigned int num)
{
	if (num > 15)
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
	unsigned int	num;
	unsigned int	n;

	num = *((unsigned int *)i);
	if (num < 0)
		n = (unsigned int)-num;
	else
		n = (unsigned int) num;
	char *base = "0123456789abcdef"; 
	return (gen_hex(base, n));
}

int ft_hexUp(void *i)
{
	unsigned int	num;
	unsigned int	n;

	num = *((unsigned int *)i);
	if (num < 0)
		n = (unsigned int)-num;
	else
		n = (unsigned int)-num;
	char *base = "0123456789ABCDEF"; 
	return (gen_hex(base, num));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:23:42 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/23 10:42:26 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"


int	ft_putlnbr(unsigned long long n, char *base)
{
	if (n < 16)
	{
		ft_putchar(&base[n]);
		return (1);
	}
	return (ft_putlnbr(n / 16, base) + ft_putlnbr(n % 16, base));
}
// (unsigned long long)p == 0
int	ft_pointer(void *ptr)
{
	if (!ptr)
		return (ft_putstr("(nil)"));
	else
		return (ft_putstr("0x") +
					ft_putlnbr((unsigned long long)ptr, "0123456789abcdef"));
}

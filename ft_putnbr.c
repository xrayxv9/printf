/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:46:35 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/23 10:31:45 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int ft_put(unsigned int n)
{
	if (n < 10)
	{
		n += '0';
		ft_putchar(&n);
		return (1);
	}
	return (ft_put(n / 10) + ft_put(n % 10));
}

int ft_putnbr(void *num)
{
	int				*i;
	int				len;
	unsigned int 	n;

	i = (int *)num;
	if (i < 0)
	{
		write(1, "-", 1);
		n = (unsigned int)(*i*-1);
	}
	else 
		n = (unsigned int)*i;

	len = ft_put(n);
	return (len);

}

int	ft_putunbr(void *num)
{
	unsigned int	n;
	int				*i;
	int				len;

	i = (int *)num;
	if (i < 0)
		n = (unsigned int) (*i * -1);
	else 
		n = (unsigned int)*i;
	len = ft_put(n);
	return (len);
}

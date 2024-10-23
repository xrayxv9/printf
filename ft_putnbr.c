/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:46:35 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/23 17:23:44 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdint.h>
int ft_put(unsigned int n, char *base)
{
	if (n > 9)
	{
		return (ft_put(n / 10, base) + ft_put(n % 10, base));
	}
	else 
	{
		n = n % 10;
		write(1, &base[n], 1);
		return (1);
	}
}

int ft_putnbr(void *num)
{
	intptr_t			i;
	int				len;
	unsigned int 	n;
	
	i = (size_t)(num);
	if (i < 0)
	{
		write(1, "-", 1);
		i = -i;
	}
	n = (unsigned int)i;
	len = ft_put(n, "0123456789");
	return (len);

}

int	ft_putunbr(void *num)
{
	unsigned int	n;
	size_t			i;
	size_t			zero;
	int				len;

	zero = 0;
	i = (size_t)num;
	if (i < zero)
		n = (unsigned int) (i * -1);
	else 
		n = (unsigned int)i;
	len = ft_put(n, "0123456789");
	return (len);
}

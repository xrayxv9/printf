/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:46:35 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/23 16:58:45 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int ft_put(unsigned int n)
{
	if (n > 9)
	{
		ft_put(n / 10);
		n = n % 10 + '0';
		printf("n = %u\n", n);
		ft_putchar(&n);
		return (1);
	}
	else if(n < 10)
	{
		n = n % 10 + '0';
		ft_putchar(&n);
		return (1);
	}
	return (0);


}

int ft_putnbr(void *num)
{
	size_t			i;
	int				len;
	unsigned int 	n;

	i = (size_t)num;
	if (i < 0)
	{
		write(1, "-", 1);
		i *= -1;
	}
	n = (unsigned int)i;
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

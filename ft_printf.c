/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:55:09 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/24 12:12:08 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// int --> void * (int) --> void * (int *) --> int * --> int
static int ft_check(char c, va_list lst, t_dico *dico)
{
	int	len;
	int (*fct)(void *);
	void *tmp;

	fct = find(dico, c);
	if (fct)
	{
		tmp = va_arg(lst, void *);
		len = fct(&tmp);
	}
	else
		len = 0;
	return (len);
}

int	error_handling(int error, t_list dico, va_list chain)
{
	va_end(chain);

}

int ft_printf(const char *s, ...)
{
	va_list	chain;
	int		len;
	t_dico	*dico;
	int		check;

	dico = create();
	va_start(chain, s);
	len = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == '%')
				check = write(1, "%", 1);
			else
				check = ft_check(*s, chain, dico);
			if (!check)
				error(1);
		}
		else
		{
			len++;
			write(1, s, 1);
		}
		s++;
		len += check;
	}
	va_end(chain);
	free(dico);
	return (len);
}

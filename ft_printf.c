/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:55:09 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/22 17:25:02 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int ft_check(char c, va_list lst, t_dico *dico)
{
	int	len;
	int (*fct)(void *);

	fct = find(dico, c);
	len += fct(va_arg(lst, void *));
	return (len);
}

int ft_printf(const char *s, ...)
{
	va_list	chain;
	int		len;
	int		i;
	t_dico	*dico;

	dico = create();
	va_start(chain, s);
	len = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			i++;
			while (s[i] == ' ')
				i++;
			len += ft_check(s[i], chain, dico);
		}
		else
		{
			len++;
			write(1, &s[i], 1);
		}
		i++;
	}
	va_end(chain);
	return (len);
}

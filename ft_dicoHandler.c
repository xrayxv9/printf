/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dicoHandler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:49:40 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/22 17:33:43 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"



static t_dico nodeMaker(char c, void (*fct)(void *))
{
	t_dico node;
	
	node.key = c;
	node.value = fct;
	return (node);
}

void	*find(t_dico *dict, char c)
{
	int	i;

	i = 0;
	while (dict[i].key && dict[i].key != c)
		i++;
	return (dict[i].value);
}


t_dico *create(void)
{
	t_dico dict[10];
	dict[9] = nodeMaker('\0', NULL);
	dict[0] = nodeMaker('c', ft_putchar);
	dict[1] = nodeMaker('s', ft_putstr);
	dict[2] = nodeMaker('p', ft_pointer);
	dict[3] = nodeMaker('d', ft_putnbr);
	dict[4] = nodeMaker('i', ft_int);
	dict[5] = nodeMaker('u', ft_unsignedNbr);
	dict[6] = nodeMaker('x', ft_hexLow);
	dict[7] = nodeMaker('X', ft_hexUp);
	dict[8] = nodeMaker('%', ft_putchar);
	return (dict);
}

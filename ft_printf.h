/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:55:34 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/24 17:07:48 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_dict
{
	char	key;
	int		(*value)(void *);
}			t_dico;

t_dico	*create(void);

void	*find(t_dico *dict, char c);

int		ft_pointer(void *ptr);

int		ft_putnbr(void *num);

int		ft_putunbr(void *num);

int		ft_hex_up(void *num);

int		ft_hex_low(void *num);

int		ft_putstr(void *s);

int		ft_putchar(void *c);

int		ft_printf(const char *s, ...);

#endif

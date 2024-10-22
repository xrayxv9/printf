/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:55:34 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/22 17:04:14 by cmorel           ###   ########.fr       */
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
	char key;
	void (*	value)(void *);
}	t_dico;

t_dico	*create(void);

void	*find(t_dico *dict, char c);

#endif

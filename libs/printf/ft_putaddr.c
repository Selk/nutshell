/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 18:55:40 by cdauphin          #+#    #+#             */
/*   Updated: 2013/12/19 18:55:40 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/libftprintf.h"

void		ft_putaddr(long unsigned int nb, char *base, int *i)
{
	size_t	beg;
	size_t	end;

	end = nb % 16;
	beg = (nb - end) / 16;
	if (beg)
	{
		*i = *i + 1;
		ft_putaddr(beg, base, &*i);
	}
	else
		*i = *i + 1;
	ft_putchar(base[end]);
}

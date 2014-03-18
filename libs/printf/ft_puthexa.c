/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 15:47:19 by cdauphin          #+#    #+#             */
/*   Updated: 2013/12/18 15:47:19 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/libftprintf.h"

void		ft_puthexa(unsigned int nb, char *base, int *i)
{
	size_t	beg;
	size_t	end;

	end = nb % 16;
	beg = (nb - end) / 16;
	if (beg)
	{
		*i = *i + 1;
		ft_puthexa(beg, base, &*i);
	}
	else
		*i = *i + 1;
	ft_putchar(base[end]);
}

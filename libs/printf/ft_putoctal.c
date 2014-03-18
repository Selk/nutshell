/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 13:00:50 by cdauphin          #+#    #+#             */
/*   Updated: 2013/12/19 13:00:50 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/libftprintf.h"

void		ft_putoctal(unsigned int nb, int *i)
{
	size_t	beg;
	size_t	end;
	char	*base;

	base = "01234567";
	end = nb % 8;
	beg = (nb - end) / 8;
	if (beg)
	{
		*i = *i + 1;
		ft_putoctal(beg, &*i);
	}
	ft_putchar(base[end]);
}

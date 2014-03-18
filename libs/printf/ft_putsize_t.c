/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsize_t.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 16:31:34 by cdauphin          #+#    #+#             */
/*   Updated: 2013/12/18 16:31:34 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/libftprintf.h"

void		ft_putsize_t(long n, int *i)
{
	if (n < 0)
		n = 4294967296 + n;
	if (n >= 10)
	{
		*i = *i + 1;
		ft_putsize_t(n / 10, &*i);
		ft_putsize_t(n % 10, &*i);
	}
	else
		ft_putchar(n + '0');
}

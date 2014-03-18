/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:07:08 by cdauphin          #+#    #+#             */
/*   Updated: 2013/11/20 11:07:08 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"includes/libftprintf.h"

int		ft_putstr(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

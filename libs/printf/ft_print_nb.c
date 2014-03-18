/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 16:06:41 by cdauphin          #+#    #+#             */
/*   Updated: 2013/12/19 16:06:41 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"includes/libftprintf.h"

int		ft_printf_di(va_list args)
{
	int		size;

	size = 0;
	ft_putnbr(ft_split(va_arg(args, int), &size));
	return (size);
}

int		ft_printf_x_min(va_list args)
{
	int		size;

	size = 0;
	ft_puthexa(va_arg(args, int), HEXA_MIN, &size);
	return (size);
}

int		ft_printf_x_cap(va_list args)
{
	int		size;

	size = 0;
	ft_puthexa(va_arg(args, int), HEXA_CAP, &size);
	return (size);
}

int		ft_printf_u(va_list args)
{
	int		size;

	size = 0;
	ft_putsize_t(va_arg(args, unsigned int), &size);
	return (size + 1);
}

int		ft_printf_o(va_list args)
{
	int		size;

	size = 0;
	ft_putoctal(va_arg(args, int), &size);
	return (size + 1);
}

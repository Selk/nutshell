/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 15:46:21 by cdauphin          #+#    #+#             */
/*   Updated: 2013/12/18 15:46:21 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"includes/libftprintf.h"

int		ft_printf_c(va_list args)
{
	ft_putchar(va_arg(args, int));
	return (1);
}

int		ft_printf_s(va_list args)
{
	int		size;
	char	*tmp;

	tmp = va_arg(args, char *);
	if (!(tmp))
	{
		ft_putstr("(null)");
		return (6);
	}
	size = ft_putstr(tmp);
	return (size);
}

int		ft_printf_p(va_list args)
{
	int						size;
	long	unsigned int	tmp;

	size = 2;
	ft_putstr("0x");
	tmp = va_arg(args, long unsigned int);
	ft_putaddr(tmp, HEXA_MIN, &size);
	return (size);
}

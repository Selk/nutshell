/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 14:57:06 by cdauphin          #+#    #+#             */
/*   Updated: 2013/12/16 14:57:06 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/libftprintf.h"

static int	ft_get_flag(char c)
{
	char	*ref;
	int		i;

	ref = "dicsuoxXp";
	i = 0;
	while (ref[i])
	{
		if (c == ref[i])
			return (i);
		i++;
	}
	return (-1);
}

int			ft_printf_sp(va_list args)
{
	if (args)
		return (ft_putchar(' '));
	else
		return (1);
}

void		ft_ini_func(int (**funct_array)(va_list args))
{
	funct_array[0] = ft_printf_di;
	funct_array[1] = ft_printf_di;
	funct_array[2] = ft_printf_c;
	funct_array[3] = ft_printf_s;
	funct_array[4] = ft_printf_u;
	funct_array[5] = ft_printf_o;
	funct_array[6] = ft_printf_x_min;
	funct_array[7] = ft_printf_x_cap;
	funct_array[8] = ft_printf_p;
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	int			(*funct_array[9])(va_list args);
	int			size;

	va_start(args, format);
	ft_ini_func(funct_array);
	i = 0;
	size = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0'
			&& ft_get_flag(format[i + 1]) != -1)
			size += funct_array[ft_get_flag(format[1 + i++])](args);
		else if (format[i] == '%' && format[i + 1] == '%')
			size += ft_putchar(format[i++]);
		else if (format[i] != '%')
			size += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (size);
}

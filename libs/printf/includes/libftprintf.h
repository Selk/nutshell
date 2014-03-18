/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 15:05:49 by cdauphin          #+#    #+#             */
/*   Updated: 2013/12/16 15:05:49 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>
# define HEXA_MIN "0123456789abcdef"
# define HEXA_CAP "0123456789ABCDEF"

int			ft_putchar(char c);
void		ft_putendl(const char *s);
void		ft_putnbr(long n);
void		ft_putsize_t(long n, int *i);
void		ft_puthexa(unsigned int nb, char *base, int *i);
void		ft_putaddr(long unsigned int nb, char *base, int *i);
void		ft_putoctal(unsigned int nb, int *i);
int			ft_putstr(const char *s);
int			ft_split(long n, int *size);
int			ft_printf_x_min(va_list args);
int			ft_printf_x_cap(va_list args);
int			ft_printf_c(va_list args);
int			ft_printf_s(va_list args);
int			ft_printf_di(va_list args);
int			ft_printf_u(va_list args);
int			ft_printf_p(va_list args);
int			ft_printf_o(va_list args);
int			ft_printf(const char *format, ...)
						__attribute__((format(printf, 1, 2)));

#endif /* !LIBFTPRINTF_H */

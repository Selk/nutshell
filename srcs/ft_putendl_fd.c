/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:23:15 by cdauphin          #+#    #+#             */
/*   Updated: 2014/03/21 10:06:18 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar_fd(char c, int fd);

void		ft_putendl_fd(const char *s, int fd)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}

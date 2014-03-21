/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:12:26 by cdauphin          #+#    #+#             */
/*   Updated: 2014/03/21 10:07:21 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp_dest;
	size_t			i;

	i = 0;
	tmp_dest = (unsigned char *)s;
	while (i < n)
	{
		tmp_dest[i] = '\0';
		i++;
	}
}

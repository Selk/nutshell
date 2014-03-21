/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:28:20 by cdauphin          #+#    #+#             */
/*   Updated: 2014/03/21 10:07:42 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t		ft_strlen(const char *str);

char		*ft_strcat(char *s1, const char *s2)
{
	size_t	dest_len;
	int		i;

	dest_len = ft_strlen(s1);
	i = 0;
	while (s2[i] != '\0')
	{
		s1[dest_len + i] = s2[i];
		i++;
	}
	s1[dest_len + i] = '\0';
	return (s1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:44:54 by cdauphin          #+#    #+#             */
/*   Updated: 2013/11/20 10:44:54 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char		*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (s2[0] == '\0')
		return ((char *)&s1[0]);
	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] == s1[i + j] && s2[j] != '\0')
			j++;
		if (s2[j] == '\0')
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}

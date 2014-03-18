/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:28:34 by cdauphin          #+#    #+#             */
/*   Updated: 2013/11/22 15:28:34 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

char		*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *) malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= (int) start && j < (int) len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	while (i >= (int) len)
	{
		str[i] = '\0';
		i--;
	}
	return (str);
}

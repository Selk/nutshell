/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opesplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 13:42:32 by cdauphin          #+#    #+#             */
/*   Updated: 2013/11/25 13:42:32 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

size_t			ft_strlen(const char *str);

char			**split(const char *s, char **str, int i, int j)
{
	int		k;

	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '|' || s[i] == '>' || s[i] == ';')
		{
			if (s[i - 1])
			{
				str[j++][k] = '\0';
				k = 0;
			}
			str[j][k++] = s[i];
			str[j++][k] = '\0';
			k = 0;
		}
		else
			str[j][k++] = s[i];
		i++;
	}
	str[j][k] = '\0';
	if (str[j][0])
		j++;
	str[j] = '\0';
	return (str);
}

char			**ft_opesplit(const char *s)
{
	char	**str;
	size_t	i;

	i = 0;
	if (!s || ft_strlen(s) == 0)
		return (0);
	str = (char **)malloc(sizeof(char *) * ft_strlen(s) + 1);
	while (i <= ft_strlen(s))
		str[i++] = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	str = split(s, str, 0, 0);
	return (str);
}

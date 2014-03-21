/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 13:42:32 by cdauphin          #+#    #+#             */
/*   Updated: 2014/03/21 10:08:05 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t		ft_strlen(const char *str);

char		**ft_strsplit(const char *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	i = j = k = 0;
	if (!s)
		return (0);
	str = (char **)x_malloc(sizeof(char *) * ft_strlen(s) + 1);
	str[0] = (char *)x_malloc(sizeof(char) * ft_strlen(s) + 1);
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] && s[i + 1] != c)
		{
			str[j][k] = '\0';
			k = 0;
			str[++j] = (char *)x_malloc(sizeof(char) * ft_strlen(s) + 1);
		}
		else if (s[i] != c)
			str[j][k++] = s[i];
		i++;
	}
	str[j + 1] = '\0';
	str[j][k] = '\0';
	return (str);
}

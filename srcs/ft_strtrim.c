/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:55:52 by cdauphin          #+#    #+#             */
/*   Updated: 2013/11/22 16:55:52 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"=

size_t		ft_strlen(const char *str);

static int	ft_comp_i(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		else
			return (i);
	}
	return (0);
}

static int	ft_comp_j(const char *s, int i)
{
	int	j;

	j = 0;
	while (s[i] != '\0')
	{
		if (!(s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			j = i;
		i++;
	}
	return (j);
}

char		*ft_strtrim(const char *s)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	if (s == NULL || ft_strlen(s) == 0)
		return (NULL);
	if (ft_strlen(s) == 1 && !(s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		return ((char *)s);
	str = (char *)x_malloc(sizeof(char) * ft_strlen((char *)s) + 1);
	if (!str)
		return (NULL);
	i = ft_comp_i(s);
	j = ft_comp_j(s, i);
	if (j == 0)
		return (0);
	while (i <= j)
		str[k++] = s[i++];
	str[k] = '\0';
	return (str);
}

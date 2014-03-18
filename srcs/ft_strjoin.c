/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:31:57 by cdauphin          #+#    #+#             */
/*   Updated: 2013/11/22 16:31:57 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

char		*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;

	str = ft_strnew(ft_strlen((char *) s1) + ft_strlen((char *) s2) + 2);
	ft_strcat(str, s1);
	ft_strcat(str, " ");
	ft_strcat(str, s2);
	return (str);
}

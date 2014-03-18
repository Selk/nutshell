/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:08:20 by cdauphin          #+#    #+#             */
/*   Updated: 2013/11/19 12:08:22 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

size_t		ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
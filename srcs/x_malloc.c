/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_malloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 15:59:53 by cdauphin          #+#    #+#             */
/*   Updated: 2014/03/19 15:59:53 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

void	*x_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr)
		return (ptr);
	else
	{
		write(2, "Malloc : fail\n", 14);
		exit(EXIT_FAILURE);
	}
}

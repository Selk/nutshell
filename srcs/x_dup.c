/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_dup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 16:10:01 by cdauphin          #+#    #+#             */
/*   Updated: 2014/03/19 16:10:01 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

int		x_dup2(int oldfd, int newfd)
{
	int		fd;

	if ((fd = dup2(oldfd, newfd)) < 0)
	{
		write(2, "Dup2 : fail\n", 12);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int		x_dup(int newfd)
{
	int		fd;

	if ((fd = dup(newfd)) < 0)
	{
		write(2, "Dup : fail\n", 11);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

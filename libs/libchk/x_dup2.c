/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_dup2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 13:23:05 by cdauphin          #+#    #+#             */
/*   Updated: 2014/01/24 13:23:05 by cdauphin         ###   ########.fr       */
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

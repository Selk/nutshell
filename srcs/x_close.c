/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_close.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 16:07:43 by cdauphin          #+#    #+#             */
/*   Updated: 2014/03/19 16:07:43 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	x_close(int fd)
{
	if (close(fd) == -1)
	{
		write(2, "Close : fail\n", 13);
		exit(EXIT_FAILURE);
	}
}

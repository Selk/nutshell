/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_read.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 17:25:45 by cdauphin          #+#    #+#             */
/*   Updated: 2014/01/09 17:25:45 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	x_read(int fd, char *buf, int buff_size)
{
	if (read(fd, buf, buff_size) == -1)
	{
		write(2, "Read : fail\n", 12);
		exit(EXIT_FAILURE);
	}
}

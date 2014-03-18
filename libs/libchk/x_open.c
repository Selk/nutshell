/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_open.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 17:25:27 by cdauphin          #+#    #+#             */
/*   Updated: 2014/01/09 17:25:27 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int		x_open(char *path, int flag, mode_t mode)
{
	int		fd;

	fd = open(path, flag, mode);
	if (fd == -1)
	{
		write(2, "Open : fail\n", 12);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

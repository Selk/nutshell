/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_tcsetattr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 14:20:43 by cdauphin          #+#    #+#             */
/*   Updated: 2014/01/10 14:20:43 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <term.h>
#include <stdlib.h>
#include <unistd.h>

void	x_tcsetattr(int fd, int options, struct termios *term)
{
	if (tcsetattr(fd, options, term) == -1)
	{
		write(2, "Tcsetattr : fail\n", 17);
		exit(EXIT_FAILURE);
	}
}

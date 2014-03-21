/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_wait.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 16:34:15 by cdauphin          #+#    #+#             */
/*   Updated: 2014/03/21 10:08:52 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

pid_t	x_wait(int *status)
{
	pid_t	pid;

	pid = wait(status);
	if (pid < 0)
	{
		write(2, "Wait : fail\n", 12);
		exit(EXIT_FAILURE);
	}
	return (pid);
}

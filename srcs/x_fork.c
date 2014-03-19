/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_fork.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 16:13:48 by cdauphin          #+#    #+#             */
/*   Updated: 2014/03/19 16:13:48 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

pid_t	x_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		write(2, "Fork : fail\n", 12);
		exit(EXIT_FAILURE);
	}
	return (pid);
}

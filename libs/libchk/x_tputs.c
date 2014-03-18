/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_tputs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 13:13:45 by cdauphin          #+#    #+#             */
/*   Updated: 2014/01/10 13:13:45 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <term.h>

void	x_tputs(char *str, int affcnt, int (*putc)(int))
{
	if (tputs(str, affcnt, putc) == -1)
	{
		write(2, "Tputs : fail\n", 13);
		exit(EXIT_FAILURE);
	}
}

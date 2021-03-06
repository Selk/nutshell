/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 15:47:17 by cdauphin          #+#    #+#             */
/*   Updated: 2013/12/18 15:47:17 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_split(long n, int *size)
{
	int		tmp;

	tmp = n;
	*size = *size + 1;
	if (n < 0)
	{
		n = -n;
		*size = *size + 1;
	}
	while (n >= 10)
	{
		n = n / 10;
		*size = *size + 1;
	}
	return (tmp);
}

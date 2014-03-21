/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 17:13:13 by cdauphin          #+#    #+#             */
/*   Updated: 2014/03/21 10:07:08 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libs/printf/includes/libftprintf.h"
#include "../includes/minishell.h"

int		b_exit(t_tree *root, t_env *env)
{
	free_tree(root);
	free_env(env);
	exit(0);
	return (1);
}

int		b_echo(t_tree *root, t_env *env)
{
	int		i;

	i = 1;
	(void)env;
	if (!root->option[1])
	{
		ft_printf("\n");
		return (1);
	}
	while (root->option[i])
	{
		if (i == 1 && ft_strcmp(root->option[1], "-n") == 0)
		{
			i++;
			continue ;
		}
		if (root->option[i + 1])
			ft_printf("%s ", root->option[i]);
		else
			ft_printf("%s", root->option[i]);
		i++;
	}
	if (root->option[1] && ft_strcmp(root->option[1], "-n") != 0)
		ft_printf("\n");
	return (1);
}

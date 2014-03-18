/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_built.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 14:21:22 by cdauphin          #+#    #+#             */
/*   Updated: 2014/03/11 14:21:22 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

static int	check_built(char *s, char *builts[7])
{
	int		i;

	i = 0;
	while (builts[i])
	{
		if (ft_strcmp(builts[i], s) == 0)
			return (i);
		i++;
	}
	return (i);
}

int			is_builtins(t_tree *root, t_env *env)
{
	int		check;
	char	*builts[7] = {"cd", "exit", "setenv", "unsetenv","env", "echo", 0};

	(void)env;
	check = check_built(root->option[0], builts);
	if (check != e_no)
		return (1);
	return (0);
}

int			builtins(t_tree *root, t_env *env)
{
	int		check;
	int		(*funct_array[6])(t_tree	*root, t_env	*env);
	char	*builts[7] = {"cd", "exit", "setenv", "unsetenv","env", "echo", 0};

	funct_array[e_cd] = b_cd;
	funct_array[e_exit] = b_exit;
	funct_array[e_setenv] = b_setenv;
	funct_array[e_unsetenv] = b_unsetenv;
	funct_array[e_env] = b_env;
	funct_array[e_echo] = b_echo;
	check = check_built(root->option[0], builts);
	if (check != e_no)
		return (funct_array[check](root, env));
	return (0);
}

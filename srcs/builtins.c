/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 17:13:13 by cdauphin          #+#    #+#             */
/*   Updated: 2014/02/07 17:13:13 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "../libs/printf/includes/libftprintf.h"
#include "../includes/minishell.h"

int		b_exit(t_tree *root, t_env *env)
{
	free_tree(root);
	free_path(env->path);
	exit(0);
	return (1);
}

int		b_env(t_tree *root, t_env *env)
{
	int		i;

	(void)root;
	i = 0;
	while (env->env[i] != '\0')
		ft_printf("%s\n", env->env[i++]);
	return (1);
}

int		b_setenv(t_tree *root, t_env *env)
{
	int		i;
	char	**tmp;

	i = 0;
	if (!root->option[1] || !root->option[2])
		return (1);
	tmp = env->env;
	env->env = (char **)malloc(sizeof(char *) * (ft_arraylen(tmp) + 2));
	while (tmp[i])
	{
		env->env[i] = ft_strdup(tmp[i]);
		i++;
	}
	env->env[i] = (char *)malloc(sizeof(char) * (ft_strlen(root->option[1])
								+ ft_strlen(root->option[2]) + 2));
	ft_strcpy(env->env[i], root->option[1]);
	ft_strcat(env->env[i], "=");
	ft_strcat(env->env[i], root->option[2]);
	env->env[i + 1] = '\0';
	return (1);
}

int		b_unsetenv(t_tree *root, t_env *env)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!root->option[0])
		return (1);
	while (env->env[i])
	{
		if (ft_strstr(env->env[i], root->option[1])
			&& env->env[i][ft_strlen(root->option[1])] == '=')
		{
			while (env->env[i])
			{
				tmp = ft_strdup(env->env[i]);
				env->env[i] = env->env[i + 1];
				env->env[i + 1] = tmp;
				i++;
				if (env->env[i - 1] == '\0')
					break ;
			}
			break ;
		}
		i++;
	}
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

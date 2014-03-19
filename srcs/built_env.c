/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 13:19:35 by cdauphin          #+#    #+#             */
/*   Updated: 2014/03/19 13:19:35 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "../libs/printf/includes/libftprintf.h"
#include "../includes/minishell.h"

static void		free_tmp(char **tmp)
{
	int		i;

	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

static char		**b_check_setenv(t_env *env, t_tree *root)
{
	char	**tmp;
	int		i;
	int		flag;

	i = 0;
	tmp = (char **)malloc(sizeof(char *) * (ft_arraylen(env->env) + 1));
	while (env->env[i])
	{
		if (ft_strstr(env->env[i], root->option[1]))
		{
			ft_putstr_fd("This variable already exist: ", 2);
			ft_putendl_fd(root->option[1], 2);
			flag = 1;
		}
		tmp[i] = ft_strdup(env->env[i]);
		i++;
	}
	tmp[i] = '\0';
	if (flag == 1)
	{
		free_tmp(tmp);
		return (0);
	}
	return (tmp);
}

int				b_env(t_tree *root, t_env *env)
{
	int		i;

	(void)root;
	i = 0;
	while (env->env[i] != '\0')
		ft_printf("%s\n", env->env[i++]);
	return (1);
}

int				b_setenv(t_tree *root, t_env *env)
{
	int		i;
	char	**tmp;

	i = 0;
	if (!root->option[1] || !root->option[2])
		return (1);
	if (!(tmp = b_check_setenv(env, root)))
		return (1);
	env->env = (char **)malloc(sizeof(char *) * (ft_arraylen(tmp) + 2));
	i = 0;
	while (tmp[i])
	{
		env->env[i] = ft_strdup(tmp[i]);
		free(tmp[i]);
		i++;
	}
	free(tmp);
	env->env[i] = (char *)malloc(sizeof(char) * (ft_strlen(root->option[1])
								+ ft_strlen(root->option[2]) + 2));
	ft_strcpy(env->env[i], root->option[1]);
	ft_strcat(env->env[i], "=");
	ft_strcat(env->env[i], root->option[2]);
	env->env[i + 1] = '\0';
	return (1);
}

int				b_unsetenv(t_tree *root, t_env *env)
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

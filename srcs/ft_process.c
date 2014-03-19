/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 11:09:25 by cdauphin          #+#    #+#             */
/*   Updated: 2013/12/27 11:09:25 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include "../libs/printf/includes/libftprintf.h"
#include "../includes/minishell.h"

static void		ft_exec(t_tree *root, t_env *env)
{
	int		pid;

	if (builtins(root, env) == 1)
		return ;
	pid = x_fork();
	if (!pid)
	{
		execve(root->cmd_final, root->option, NULL);
		env->last = FAILLURE;
		exit(0);
	}
	else
	{
		wait(0);
		env->last = SUCCESS;
	}
}

static int		ft_error_test(t_tree *root, t_env *env)
{
	if (is_builtins(root, env) == 1)
		return (0);
	if (!(root->cmd_final) && ft_strcmp(root->type, "CMD") == 0)
	{
		ft_putstr_fd("Nutshell: command not found: ", 2);
		ft_putendl_fd(root->option[0], 2);
		env->last = FAILLURE;
		return (1);
	}
	return (0);
}

static void		get_cmd(t_tree *root, t_env *env, int i)
{
	if (access(env->tmp[i], X_OK) == 0)
		root->cmd_final = ft_strdup(env->tmp[i]);
	if (access(root->option[0], X_OK) == 0)
		root->cmd_final = ft_strdup(root->option[0]);
}

void			ft_process(t_tree *root, t_env *env)
{
	int		i;
	void	(*funct_array[8])(t_tree	*root, t_env	*env);
	char	*types[8] = {"OP_SEMI", "OP_PIPE", "OP_OR", "OP_AND", "OP_REDL"
	, "OP_REDR", "OP_DREDR", NULL};

	funct_array[0] = ft_semi;
	funct_array[1] = ft_pipe;
	funct_array[2] = ft_or;
	funct_array[3] = ft_and;
	funct_array[4] = ft_redl;
	funct_array[5] = ft_redr;
	funct_array[6] = ft_redr;
	funct_array[7] = ft_exec;
	if (ft_error_test(root, env) == 1)
		return ;
	i = 0;
	while (types[i])
	{
		if (ft_strstr(types[i], root->type))
			break ;
		i++;
	}
	funct_array[i](root, env);
}

int				ft_cmd_path(t_tree *root, t_env *env)
{
	int		i;

	i = 0;
	if (is_builtins(root, env) == 1)
		return (0);
	if (ft_strcmp(root->type, "CMD") == 0)
	{
		env->tmp = (char **)x_malloc(sizeof(char *) * ft_arraylen(env->path));
		while (env->path[i] != '\0')
		{
			env->tmp[i] = ft_strdup(env->path[i]);
			env->tmp[i] = ft_strcat(env->tmp[i], "/");
			env->tmp[i] = ft_strcat(env->tmp[i], root->option[0]);
			get_cmd(root, env, i);
			free(env->tmp[i]);
			i++;
		}
		free(env->tmp);
	}
	if (root->left)
		ft_cmd_path(root->left, env);
	if (root->right)
		ft_cmd_path(root->right, env);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 14:17:46 by cdauphin          #+#    #+#             */
/*   Updated: 2014/03/11 14:17:46 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "../includes/minishell.h"

void	ft_semi(t_tree *root, t_env *env)
{
	int		pid;

	pid = x_fork();
	if (!pid)
	{
		ft_process(root->left, env);
		exit(0);
	}
	else
	{
		x_wait(0);
		ft_process(root->right, env);
	}
}

void	ft_or(t_tree *root, t_env *env)
{
	ft_process(root->left, env);
	if (env->last == FAILLURE)
		ft_process(root->right, env);
}

void	ft_and(t_tree *root, t_env *env)
{
	ft_process(root->left, env);
	if (env->last == SUCCESS)
		ft_process(root->right, env);
}

void	ft_pipe(t_tree *root, t_env *env)
{
	int		fd[2];
	int		pid;
	int		stdcpy;

	pipe(fd);
	pid = x_fork();
	stdcpy = x_dup(0);
	if (!pid)
	{
		x_close(fd[0]);
		x_dup2(fd[1], 1);
		x_close(fd[1]);
		ft_process(root->left, env);
		exit(0);
	}
	else
	{
		x_wait(0);
		x_close(fd[1]);
		x_dup2(fd[0], 0);
		x_close(fd[0]);
		ft_process(root->right, env);
		x_dup2(stdcpy, 0);
	}
}

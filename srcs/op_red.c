/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_red.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 14:12:20 by cdauphin          #+#    #+#             */
/*   Updated: 2014/03/12 14:12:20 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <fcntl.h>
#include "../includes/minishell.h"
#include "../libs/printf/includes/libftprintf.h"

void		ft_redl(t_tree *root, t_env *env)
{
	int		file;
	int		pid;

	pid = x_fork();
	if (!pid)
	{
		if ((file = open(root->right->data, O_RDONLY)) == -1)
		{
			ft_putstr_fd("No such file or directory: ", 2);
			ft_putendl_fd(root->right->data, 2);
			exit(0);
		}
		x_dup2(file, 0);
		x_close(file);
		ft_process(root->left, env);
		exit(0);
	}
	else
		x_wait(0);
}

void		ft_redr(t_tree *root, t_env *env)
{
	int		file;
	int		pid;

	pid = x_fork();
	if (!pid)
	{
		if (ft_strstr(root->type, "DREDR"))
			file = open(root->right->data, O_RDWR | O_CREAT
							| O_APPEND, S_IREAD | S_IWRITE);
		else
			file = open(root->right->data, O_RDWR | O_CREAT
							| O_TRUNC, S_IREAD | S_IWRITE);
		if (file < 0)
		{
			ft_putstr_fd("Error : bad selected file: ", 2);
			ft_putendl_fd(root->right->data, 2);
			exit(0);
		}
		x_dup2(file, 1);
		x_close(file);
		ft_process(root->left, env);
		exit(0);
	}
	else
		x_wait(0);
}

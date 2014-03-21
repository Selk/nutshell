/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 13:52:36 by cdauphin          #+#    #+#             */
/*   Updated: 2014/03/21 10:07:14 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/minishell.h"
#include "../libs/printf/includes/libftprintf.h"

void		free_tree(t_tree *root)
{
	int		i;

	i = 0;
	free(root->data);
	free(root->type);
	while (root->option[i])
		free(root->option[i++]);
	free(root->cmd_final);
	root->cmd_final = NULL;
	free(root->option);
	free(root);
	if (root->left)
		free_tree(root->left);
	if (root->right)
		free_tree(root->right);
}

void		free_env(t_env *env)
{
	int		i;

	i = 0;
	while (env->path[i])
	{
		free(env->path[i]);
		i++;
	}
	free(env->path);
	i = 0;
	while (env->env[i])
	{
		free(env->env[i]);
		i++;
	}
	free(env->env);
	free(env->fst_cmd);
	free(env);
}

void		free_tokens(char ***tokens)
{
	int		i;
	int		j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (tokens[i][j])
		{
			free(tokens[i][j]);
			tokens[i][j] = NULL;
			j++;
		}
		free(tokens[i]);
		tokens[i] = NULL;
		i++;
	}
	free(tokens);
	tokens = NULL;
}

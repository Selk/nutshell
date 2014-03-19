/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 13:52:36 by cdauphin          #+#    #+#             */
/*   Updated: 2014/03/14 13:52:36 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "../includes/minishell.h"

void			free_tree(t_tree *root)
{
	int		i;

	i = 0;
	free(root->data);
	free(root->type);
	if (root->option)
		while (root->option[i])
			free(root->option[i++]);
	if (root->cmd_final)
		free(root->cmd_final);
	free(root->option);
	free(root);
	if (root->left)
		free_tree(root->left);
	if (root->right)
		free_tree(root->right);
}

void			free_path(char **path)
{
	int		i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}

void		free_env(char **tmp)
{
	int		i;

	if (tmp)
	{
		i = 0;
		while (tmp[i])
		{
			if (tmp[i])
				free(tmp[i]);
			i++;
		}
		free(tmp);
	}
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

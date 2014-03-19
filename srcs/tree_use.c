/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_use.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 09:58:10 by cdauphin          #+#    #+#             */
/*   Updated: 2014/01/22 09:58:10 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "../includes/minishell.h"
#include "../libs/printf/includes/libftprintf.h"

static void		tree_add_bis(t_tree *tmp_tree, int key, t_tree *root)
{
	t_tree	*tmp_node;

	while (tmp_tree)
	{
		tmp_node = tmp_tree;
		if (key > tmp_tree->key)
		{
			tmp_tree = tmp_tree->right;
			if (!tmp_tree)
				tmp_node->right = root;
		}
		else
		{
			tmp_tree = tmp_tree->left;
			if (!tmp_tree)
				tmp_node->left = root;
		}
	}
}

static void		tree_add(t_tree **tree, char **cmd, int key)
{
	t_tree	*tmp_tree;
	t_tree	*root;

	tmp_tree = *tree;
	root = (t_tree *)malloc(sizeof(t_tree));
	root->key = key;
	root->data = ft_strdup(cmd[0]);
	root->option = ft_strsplit(cmd[0], ' ');
	root->type = ft_strdup(cmd[1]);
	root->left = NULL;
	root->right = NULL;
	root->cmd_final = NULL;
	if (tmp_tree)
		tree_add_bis(tmp_tree, key, root);
	else
		*tree = root;
}

static char		***get_options(char ***tokens, char *type)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (tokens[1][i] != '\0')
	{
		if (ft_strcmp(tokens[1][i], type) == 0 && tokens[1][i + 1])
		{
			j = i++;
			k = i;
			while (ft_strstr(tokens[1][k], "ARG"))
			{
				tokens[0][j] = ft_strjoin(tokens[0][j], tokens[0][k]);
				k++;
			}
		}
		i++;
	}
	return (tokens);
}

void			add_elem_tree(char ***tokens, char *type, t_tree **tree)
{
	int		i;
	char	*tmp[2];

	if (ft_strcmp(type, "CMD") == 0)
		tokens = get_options(tokens, type);
	i = 0;
	while (tokens[1][i] && !ft_strstr(type, "ARG"))
	{
		if (ft_strcmp(tokens[1][i], type) == 0)
		{
			tmp[0] = ft_strdup(tokens[0][i]);
			tmp[1] = ft_strdup(tokens[1][i]);
			tree_add(&*tree, tmp, i + 1);
			free(tmp[0]);
			free(tmp[1]);
		}
		i++;
	}
}

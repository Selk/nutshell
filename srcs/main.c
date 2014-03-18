/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 13:33:57 by cdauphin          #+#    #+#             */
/*   Updated: 2014/01/27 13:33:57 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <term.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include "../includes/termcaps.h"
#include "../libs/printf/includes/libftprintf.h"
#include "../includes/minishell.h"

static void		ft_get_path(t_env *val)
{
	int		i;
	int		j;
	char	*str;

	i = 5;
	j = 0;
	while (val->env[j] != '\0')
	{
		if (val->env[j][0] == 'P' && val->env[j][1] == 'A'
			&& val->env[j][2] == 'T' && val->env[j][3] == 'H')
			break ;
		else
			j++;
	}
	str = (char *)malloc(sizeof(char) * ft_strlen(val->env[j]) - 4);
	while (val->env[j][i] != '\0')
	{
		str[i - 5] = val->env[j][i];
		i++;
	}
	val->path = ft_strsplit(str, ':');
	free(str);
	str = NULL;
}

void			aff(t_tree *root, int prof)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i++ < prof)
		ft_printf(" -  ");
	while (root->option[j] != '\0')
		ft_printf("[%s] ", root->option[j++]);
	ft_printf("- [%s] ", root->type);
	if (root->prev)
		ft_printf("|| prev = [%s]", root->prev->data);
	ft_printf("\n");
	if (root->left)
		aff(root->left, prof + 1);
	if (root->right)
		aff(root->right, prof + 1);
}

int				main(int argc, char *argv[], char *envp[])
{
	t_tree		*tree;
	t_env		*env;
	char		buf[SIZE];
	int			ret;

	env = (t_env *)malloc(sizeof(t_env));
	env->env = envp;
	ft_get_path(env);
	while (argv || argc)
	{
		ft_bzero(buf, SIZE);
		ft_printf("Nutshell $>");
		env->last = FAILLURE;
		if ((ret = read(0, buf, SIZE)) < 2)
			continue ;
		buf[ret - 1] = '\0';
		env->fst_cmd = ft_strdup(buf);
		if (!(tree = init_tree(env->fst_cmd)))
			continue ;
		ft_cmd_path(tree, env);
		ft_process(tree, env);
	}
	return (0);
}

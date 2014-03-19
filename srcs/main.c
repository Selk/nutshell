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

static void		get_path(t_env *val)
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
	str = (char *)x_malloc(sizeof(char) * ft_strlen(val->env[j]) - 4);
	while (val->env[j][i] != '\0')
	{
		str[i - 5] = val->env[j][i];
		i++;
	}
	val->path = ft_strsplit(str, ':');
	free(str);
	str = NULL;
}

static char		**get_env(char **envp)
{
	char		**env;
	int			i;

	i = 0;
	env = (char **)x_malloc(sizeof(char *) * ft_arraylen(envp));
	while (envp[i])
	{
		env[i] = ft_strdup(envp[i]);
		i++;
	}
	return (env);
}

static void		print_prompt(void)
{
	char		*pwd;
	int			i;
	int			j;

	i = j = 0;
	pwd = getcwd(pwd, SIZE);
	while (pwd[i])
	{
		i++;
		if (pwd[i] == '/')
			j = i;
	}
	j++;
	while (pwd[j])
	{
		write(1, &pwd[j], 1);
		j++;
	}
}

int				main(int argc, char *argv[], char *envp[])
{
	t_tree		*tree;
	t_env		*env;
	char		buf[SIZE];
	int			ret;

	env = (t_env *)x_malloc(sizeof(t_env));
	env->env = get_env(envp);
	get_path(env);
	while (argv || argc)
	{
		ft_bzero(buf, SIZE);
		print_prompt();
		ft_printf(" $>");
		if ((ret = read(0, buf, SIZE)) < 2)
			continue ;
		buf[ret - 1] = '\0';
		env->fst_cmd = ft_strdup(buf);
		if (!(tree = init_tree(env->fst_cmd)))
			continue ;
		ft_cmd_path(tree, env);
		ft_process(tree, env);
		free_tree(tree);
		free(env->fst_cmd);
	}
	return (0);
}

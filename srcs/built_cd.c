/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 13:37:25 by cdauphin          #+#    #+#             */
/*   Updated: 2014/02/13 13:37:25 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <sys/stat.h>
#include "../libs/printf/includes/libftprintf.h"
#include "../includes/minishell.h"

static void		put_oldpwd(char *pwd, t_env *env)
{
	int		i;

	i = 0;
	while (env->env[i])
	{
		if (ft_strstr(env->env[i], "OLDPWD") && env->env[i][6] == '=')
		{
			env->env[i] = (char *)malloc(sizeof(char) * (ft_strlen(pwd) + 8));
			ft_strcpy(env->env[i], "OLDPWD=");
			ft_strcat(env->env[i], pwd);
		}
		i++;
	}
	free(pwd);
}

static char		*put_pwd(char *pwd, t_env *env)
{
	int		i;
	char	*tmp;

	i = 0;
	while (env->env[i])
	{
		if (ft_strstr(env->env[i], "PWD") && env->env[i][3] == '=')
		{
			tmp = ft_strdup(ft_strsub(ft_strstr(env->env[i], "PWD="), 4
							, ft_strlen(ft_strstr(env->env[i], "PWD="))));
			env->env[i] = (char *)malloc(sizeof(char) * (ft_strlen(pwd) + 5));
			ft_strcpy(env->env[i], "PWD=");
			ft_strcat(env->env[i], pwd);
		}
		i++;
	}
	return (tmp);
}

static void		home_cd(t_env *env)
{
	int		i;
	char	*tmp;

	i = 0;
	while (env->env[i])
	{
		if (ft_strstr(env->env[i], "HOME=") && env->env[i][4] == '=')
		{
			tmp = ft_strdup(ft_strsub(ft_strstr(env->env[i], "HOME="), 5
						, ft_strlen(ft_strstr(env->env[i], "HOME="))));
			chdir(tmp);
			put_oldpwd(put_pwd(tmp, env), env);
		}
		i++;
	}
}

static void		back_cd(t_env *env)
{
	int		i;
	char	*tmp;

	i = 0;
	while (env->env[i])
	{
		if (ft_strstr(env->env[i], "OLDPWD=") && env->env[i][6] == '=')
		{
			tmp = ft_strdup(ft_strsub(ft_strstr(env->env[i], "OLDPWD="), 7
						, ft_strlen(ft_strstr(env->env[i], "OLDPWD="))));
			chdir(tmp);
			put_oldpwd(put_pwd(tmp, env), env);
		}
		i++;
	}
}

int				b_cd(t_tree *root, t_env *env)
{
	struct stat		pathstat;
	char			*pwd;

	if (!root->option[1])
		home_cd(env);
	else if (ft_strcmp(root->option[1], "-") == 0)
		back_cd(env);
	else if (stat(root->option[1], &pathstat) < 0)
		ft_printf("cd : no such file or directory: %s\n", root->option[1]);
	else if (!(S_ISDIR(pathstat.st_mode)))
		ft_printf("cd : not a directory: %s\n", root->option[1]);
	else if (!(pathstat.st_mode & S_IXUSR))
		ft_printf("cd : permission denied: %s\n", root->option[1]);
	else
	{
		chdir(root->option[1]);
		pwd = NULL;
		pwd = getcwd(pwd, SIZE);
		put_oldpwd(put_pwd(pwd, env), env);
	}
	return (1);
}

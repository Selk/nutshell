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

static char		*get_tmp(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;

	i = j = 0;
	while (str[i])
	{
		if (str[i++] == '=')
			break ;
	}
	len = ft_strlen(str) - i;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	while (str[i])
	{
		tmp[j] = str[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

static void		put_oldpwd(char *pwd, t_env *env)
{
	int		i;

	i = 0;
	while (env->env[i])
	{
		if (ft_strstr(env->env[i], "OLDPWD") && env->env[i][6] == '=')
		{
			free(env->env[i]);
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
			tmp = get_tmp(ft_strstr(env->env[i], "PWD="));
			free(env->env[i]);
			env->env[i] = (char *)malloc(sizeof(char) * (ft_strlen(pwd) + 5));
			ft_strcpy(env->env[i], "PWD=");
			ft_strcat(env->env[i], pwd);
		}
		i++;
	}
	return (tmp);
}

static void		cd(t_env *env, char *type)
{
	int		i;
	char	*tmp;

	i = 0;
	while (env->env[i])
	{
		if (ft_strstr(env->env[i], type) && env->env[i][6] == '=')
		{
			tmp = get_tmp(ft_strstr(env->env[i], type));
			if (ft_strcmp(type, "OLDPWD=") == 0)
				ft_printf("%s\n", tmp);
			chdir(tmp);
			put_oldpwd(put_pwd(tmp, env), env);
			free(tmp);
		}
		i++;
	}
}

int				b_cd(t_tree *root, t_env *env)
{
	struct stat		pathstat;
	char			*pwd;

	if (!root->option[1])
		cd(env, "HOME=");
	else if (ft_strcmp(root->option[1], "-") == 0)
		cd(env, "OLDPWD=");
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
		free(pwd);
	}
	return (1);
}

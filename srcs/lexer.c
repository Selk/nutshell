/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 14:41:37 by cdauphin          #+#    #+#             */
/*   Updated: 2014/02/26 14:41:37 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "../libs/printf/includes/libftprintf.h"
#include "../includes/minishell.h"

static char		*get_token(char *cmd, char *tok[7], int flag)
{
	int		i;
	char	*tokens[12] = {"OP_SEMI", "OP_PIPE", "OP_OR", "OP_AND", "OP_REDL"
	, "OP_REDR", "OP_DREDR", "REDL_FILE", "REDR_FILE", "CMD_ARG", "CMD", NULL};

	i = 0;
	while (tok[i])
	{
		if (ft_strcmp(tok[i], cmd) == 0)
			return (tokens[i]);
		i++;
	}
	return (tokens[flag]);
}

static int		get_flag(char *s)
{
	if (s)
	{
		if (ft_strstr(s, "REDR"))
			return (e_f_redr);
		else if (ft_strstr(s, "OP_REDL"))
			return (e_f_redl);
		else if (ft_strstr(s, "CMD"))
			return (e_cmd_arg);
	}
	return (e_cmd);
}

static int		check_cmd(char *s1, char *s2)
{
	if ((!ft_strcmp(s1, "CMD") || ft_strstr(s1, "FILE"))
		&& ft_strisalnum(s2) == 0)
	{
		ft_putstr_fd("Command name of file name must be alphanumeric: ", 2);
		ft_putstr_fd(s2, 2);
		ft_putstr_fd("\n", 2);
		return (FAILLURE);
	}
	return (SUCCESS);
}

static char		*get_tab_out(char *cmd)
{
	int		i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\t')
			cmd[i] = ' ';
		i++;
	}
	return (cmd);
}

char			***lexer(char *cmd)
{
	int			i;
	char		***token;
	char		*tok[8] = {";", "|", "||", "&&", "<", ">", ">>", NULL};

	i = 0;
	token = (char ***)x_malloc(sizeof(char **) * 2);
	cmd = ft_strtrim(cmd);
	if (!cmd)
		return (FAILLURE);
	cmd = get_tab_out(cmd);
	token[0] = ft_strsplit(cmd, ' ');
	token[1] = (char **)x_malloc(sizeof(char *) * (ft_arraylen(token[0]) + 1));
	while (token[0][i])
	{
		if (i == 0)
			token[1][i] = ft_strdup(get_token(token[0][i], tok, e_cmd));
		else
			token[1][i] = ft_strdup(get_token(token[0][i]
								, tok, get_flag(token[1][i - 1])));
		if (check_cmd(token[1][i], token[0][i]) == FAILLURE)
			return (FAILLURE);
		i++;
	}
	token[1][i] = 0;
	return (token);
}

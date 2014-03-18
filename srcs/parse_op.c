/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 17:12:36 by cdauphin          #+#    #+#             */
/*   Updated: 2014/02/25 17:12:36 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libs/printf/includes/libftprintf.h"
#include "../includes/minishell.h"

static int	error(int index, int flag)
{
	int			i;
	char		*tok[8] = {";", "|", "||", "&&", "<", ">", ">>", NULL};
	char		*flags[] =
	{
		[0] = "Invalid null command.\n",
		[1] = "Ambiguous output redirect.\n",
		[2] = "Parse error near '\\n'\n",
		[3] = NULL,
	};

	if (flag != FAILLURE)
		ft_printf("%s", flags[-flag - 1]);
	i = 0;
	while (tok[i] && flag == FAILLURE)
	{
		if (i == index)
			ft_printf("Parse error near : '%s'\n", tok[i]);
		i++;
	}
	return (FAILLURE);
}

int			parse_op_semi(char **tok, int i, int index)
{
	if (tok[i + 1] && ft_strstr(tok[i + 1], "OP")
		&& ft_strstr(tok[i + 1], "REDR"))
		return (error(index, BS_N));
	if (tok[i + 1] && ft_strstr(tok[i + 1], "OP")
		&& !ft_strstr(tok[i + 1], "REDL") && !ft_strstr(tok[i + 1], "SEMI"))
		return (error(index, FAILLURE));
	if (!tok[i - 1] || !tok[i + 1])
		return (error(index, FAILLURE));
	return (SUCCESS);
}

int			parse_op(char **tok, int i, int index)
{
	if (!tok[i - 1] || !tok[i + 1])
		return (error(index, FAILLURE));
	if (ft_strstr(tok[i + 1], "OP") && ft_strcmp(tok[i + 1], "OP_REDL") != 0)
		return (error(index, FAILLURE));
	if (ft_strstr(tok[i - 1], "OP"))
		return (error(index, FAILLURE));
	return (SUCCESS);
}

int			parse_op_redr(char **tok, int i, int index)
{
	if (!tok[i - 1])
		return (error(index, NULL_CMD));
	if (!tok[i + 1])
		return (error(index, FAILLURE));
	if (tok[i + 2] && ft_strstr(tok[i + 2], "REDR"))
		return (error(index, AMBI_OUT));
	if (ft_strstr(tok[i + 1], "OP") || ft_strstr(tok[i - 1], "OP"))
		return (error(index, FAILLURE));
	return (SUCCESS);
}

int			parse_op_redl(char **tok, int i, int index)
{
	if (!tok[i + 1])
		return (error(index, BS_N));
	if (ft_strstr(tok[i + 1], "OP_REDL"))
		return (error(index, FAILLURE));
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 16:45:58 by cdauphin          #+#    #+#             */
/*   Updated: 2014/02/25 16:45:58 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libs/printf/includes/libftprintf.h"
#include "../includes/minishell.h"

static int		no_need_parse(char **tok, int i, int index)
{
	(void)tok;
	i = index = 0;
	return (1);
}

static int		get_index(char *s, char *tokens[12])
{
	int		i;

	i = 0;
	while (tokens[i])
	{
		if (ft_strcmp(s, tokens[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

static void		init_func(int (**parse)(char **tokens, int i, int index))
{
	parse[e_op_semi] = parse_op_semi;
	parse[e_op_pipe] = parse_op;
	parse[e_op_or] = parse_op;
	parse[e_op_and] = parse_op;
	parse[e_op_redl] = parse_op_redl;
	parse[e_op_redr] = parse_op_redr;
	parse[e_op_dredr] = parse_op_redr;
	parse[e_f_redl] = no_need_parse;
	parse[e_f_redr] = no_need_parse;
	parse[e_cmd_arg] = no_need_parse;
	parse[e_cmd] = no_need_parse;
}

char			***parser(char ***tokens)
{
	int		(*parse[11])(char	**tokens, int	i, int	index);
	int		i;
	int		index;
	char	*tok[12] = {"OP_SEMI", "OP_PIPE", "OP_OR", "OP_AND", "OP_REDL"
	, "OP_REDR", "OP_DREDR", "REDL_FILE", "REDR_FILE", "CMD_ARG", "CMD", NULL};

	if (!tokens)
		return (FAILLURE);
	init_func(parse);
	i = 0;
	while (tokens[1][i])
	{
		index = get_index(tokens[1][i], tok);
		if (parse[index](tokens[1], i, index) == 0)
			return (FAILLURE);
		i++;
	}
	return (tokens);
}

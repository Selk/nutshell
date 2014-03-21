/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 17:08:27 by cdauphin          #+#    #+#             */
/*   Updated: 2014/03/21 10:08:14 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <term.h>
#include "../libs/printf/includes/libftprintf.h"
#include "../includes/minishell.h"

char		init(char buf)
{
	ft_printf("%s", tgetstr("sc", NULL));
	ft_printf("%c", buf);
	return (buf);
}

t_tree		*init_tree(char *cmd)
{
	t_tree		*tree;
	char		***tokens;

	if (!(tokens = parser(lexer(cmd))))
		return (FAILLURE);
	tree = NULL;
	add_elem_tree(tokens, "OP_SEMI", &tree);
	add_elem_tree(tokens, "OP_AND", &tree);
	add_elem_tree(tokens, "OP_OR", &tree);
	add_elem_tree(tokens, "OP_PIPE", &tree);
	add_elem_tree(tokens, "OP_REDR", &tree);
	add_elem_tree(tokens, "OP_DREDR", &tree);
	add_elem_tree(tokens, "OP_REDL", &tree);
	add_elem_tree(tokens, "REDR_FILE", &tree);
	add_elem_tree(tokens, "REDL_FILE", &tree);
	add_elem_tree(tokens, "CMD", &tree);
	add_elem_tree(tokens, "CMD_ARG", &tree);
	free_tokens(tokens);
	return (tree);
}

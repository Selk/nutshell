/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 14:54:11 by cdauphin          #+#    #+#             */
/*   Updated: 2014/03/12 14:54:11 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef TERMCAPS_H
# define TERMCAPS_H
# define UP 65
# define DO 66
# define LE 68
# define RI 67

typedef struct		s_ed
{
	char			c;
	struct s_ed		*next;
	struct s_ed		*prev;
}					t_ed;

typedef struct		s_ed_dlist
{
	size_t			length;
	t_ed			*curr;
	t_ed			*head;
	t_ed			*tail;
}					t_ed_dlist;

#endif /* !TERMCAPS_H */

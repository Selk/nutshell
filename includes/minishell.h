/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdauphin <cdauphin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 12:42:51 by cdauphin          #+#    #+#             */
/*   Updated: 2013/12/23 12:42:51 by cdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINISHELL_H
# define MINISHELL_H
# define SIZE 256
# include <unistd.h>


# define BS			127
# define ARR		27
# define LE			68
# define RI			67
# define UP			65
# define DO			66
# define HO			72
# define EN			70
# define CC			3
# define CD			4
# define CL			12
# define RET		10
# define TAB		'\t'
# define SUCCESS	1
# define FAILLURE	0
# define NULL_CMD	-1
# define AMBI_OUT	-2
# define BS_N		-3


typedef struct			s_tree
{
	int					key;
	char				*data;
	char				*type;
	char				**option;
	char				*cmd_final;
	struct s_tree		*prev;
	struct s_tree		*left;
	struct s_tree		*right;
}						t_tree;

typedef enum			e_tokens
{
	e_op_semi,
	e_op_pipe,
	e_op_or,
	e_op_and,
	e_op_redl,
	e_op_redr,
	e_op_dredr,
	e_f_redl,
	e_f_redr,
	e_cmd_arg,
	e_cmd,
}						t_tokens;

typedef enum			e_builts
{
	e_cd,
	e_exit,
	e_setenv,
	e_unsetenv,
	e_env,
	e_echo,
	e_no,
}						t_builts;

typedef struct			s_index
{
	int					i;
	int					flag;
}						t_index;

typedef struct			s_dl_list
{
	char				*data;
	int					i;
	struct s_dl_list	*next;
	struct s_dl_list	*prev;
}						t_dl_list;

typedef struct			s_hist
{
	t_dl_list			*lh;
	t_dl_list			*ci;
}						t_hist;

typedef struct			s_env
{
	char				**tmp;
	char				**env;
	char				**path;
	int					last;
	char				*fst_cmd;
}						t_env;

/*
**	process
*/
int			get_next_line(int fd, char **line);
void		add_elem_tree(char ***tokens, char *type, t_tree **tree);
int			ft_cmd_path(t_tree *root, t_env *env);
void		ft_runsource(t_tree *root, int fd[2]);
void		ft_rundest(t_tree *root, int fd[2]);
void		ft_process(t_tree *root, t_env *env);
t_hist		init_shell(t_hist hist, int *i);
char		init(char buf);
t_tree		*init_tree(char *cmd);

/*
**	op_exec
*/
void		ft_semi(t_tree *root, t_env *env);
void		ft_or(t_tree *root, t_env *env);
void		ft_and(t_tree *root, t_env *env);
void		ft_pipe(t_tree *root, t_env *env);
void		ft_redl(t_tree *root, t_env *env);
void		ft_redr(t_tree *root, t_env *env);

/*
**	lexer
*/
char		***lexer(char *cmd);

/*
**	parser
*/
char		***parser(char ***tokens);
int			parse_op(char **tok, int i, int index);
int			parse_op_redr(char **tok, int i, int index);
int			parse_op_redl(char **tok, int i, int index);
int			parse_op_semi(char **tok, int i, int index);

/*
**	free
*/
void			free_tree(t_tree *root);
void			free_path(char **path);
void		free_tokens(char ***tokens);

/*
**	builtins
*/
int			is_builtins(t_tree *root, t_env *env);
int			builtins(t_tree *root, t_env *env);
int			b_exit(t_tree *root, t_env *env);
int			b_env(t_tree *root, t_env *env);
int			b_setenv(t_tree *root, t_env *env);
int			b_unsetenv(t_tree *root, t_env *env);
int			b_cd(t_tree *root, t_env *env);
int			b_echo(t_tree *root, t_env *env);

/*
**	libft
*/
char		**ft_strsplit(const char *s, char c);
char		**ft_opesplit(const char *s, char **str);
size_t		ft_strlen(const char *str);
size_t		ft_arraylen(char **array);
char		*ft_strchr(const char *src, int c);
void		ft_putendl_fd(const char *s, int fd);
void		ft_putstr_fd(const char *s, int fd);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *src);
char		*ft_strtrim(const char *s);
void		**ft_trim(char ***s);
void		ft_bzero(void *s, size_t n);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strcpy(char *s1, const char *s2);
char		*ft_strstr(const char *s1, const char *s2);
char		*ft_strsub(const char *s, unsigned int start, size_t len);
int			ft_isalnum(int c);
int			ft_strisalnum(char *s);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strnew(size_t size);

/*
**	libchk
*/
void		x_read(int fd, char *buf, int buff_size);
int			x_open(char *path, int flag, mode_t mode);
void		*x_malloc(size_t size);
void		x_close(int fd);
int			x_dup2(int oldfd, int newfd);
void		x_tputs(const char *str, int affcnt, int (*putc)(int));

#endif /* !MINISHELL_H */

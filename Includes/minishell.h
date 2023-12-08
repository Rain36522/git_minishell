/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:21:32 by pudry             #+#    #+#             */
/*   Updated: 2023/12/08 09:34:49 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (10)
# endif

# include "../ft_printf/ft_printf.h"
# include "../ft_printf/libft/libft.h"

# include "header_builtin.h"
# include "../execution/pipex.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
# include <errno.h>
# include <fcntl.h>
# include <signal.h>

# ifndef S_DATA
#  define S_DATA

typedef struct s_data
{
	char			**env;
	pid_t			pid;
	int				iexit;
	int				imem_exit;
}				t_data;
# endif

typedef struct s_incmd
{
	struct s_incmd	*next;
	char			*wrd;
	int				fd[2];
	char			*read_fd;
}				t_incmd;

typedef struct s_dlist
{
	char			*input;
	char			*str;
	int				i;
	int				qdouble;
	int				state;
}				t_dlist;

typedef struct s_lst
{
	struct s_lst	*next;
	char			*str;
}	t_lst;

typedef struct s_acmds
{
	char	**array;
	int		fd_pipe[2];
	int		isize;
}	t_acmd;

// This funtion is for giving error message, exit programm
// or return NULL value needed
void	ft_error_msg(int i);
int		ft_error_int(int icode, int iexit, char **array, char *str);
void	*ft_error_ptr(int icode, int iexit, char **array, char *str);
void	*ft_error_child(int icode, char **array, char *str, char *str2);
void	*ft_error_get_cmd(int icode, char **env, char *str, char *str2);

// GNL
char	*get_next_line(int fd);

// This functions are for taking the input
t_acmd	*get_cmd(char *prompt, t_data *data);
t_incmd	*ft_free_lst(t_incmd *lst, char *scmd);
int		ft_check_syntax(char **array);
void	write_cmd_in_file(char *scmd, int fd);
t_incmd	*ft_make_lst(char **array);
t_incmd	*ft_free_lst(t_incmd *lst, char *str);
void	ft_write_file(t_incmd *lst, char **array, t_data *data);
t_acmd	*ft_file_to_array(int fd, int fd_out, t_data *data);
char	**ft_replace_redir(t_incmd *lst, char **array);
void	ft_put_data(char **array, int fd);
t_lst	*ft_utils_open_quotes(t_lst *ptr, t_lst *lst, int fd);
void	ft_free_file_lst(t_lst *lst, int ierror, char **array);
char	*ft_strdup_remov(char *str, t_acmd	*cmd);
char	*input_error(char *scmd);
t_incmd	*redir_lst(char *scmd);
t_acmd	*treat_input(t_acmd *acmd_data, t_data *data);

// ft_split
char	**ft_split_minishell(char const *s);
int		dup_str(char **tab, const char *s, int i);
int		len_dup_str(const char *s, int i);
int		spe_case_out_quotes(char c);
int		dup_pip_dir(char **tab, const char *s, int i, char c);
char	**free_split(char **tab);
int		str_nbr(char const *s, int i, int j);
int		skip_pipe_or_dir(const char *s, int i, char c);
int		check_spe_case(char c);
int		skip_until(const char *s, int i, char c);
char	*from_quotes_to_wrds(char *str);

// utils
char	*ft_give_prompte(char **env);
void	*ft_malloc(int isize, int ilength, char **array, char *str);
int		ft_check_is_quote(char c, int i);
int		ft_str_end_quotes(char *str, int i);
int		ft_quotes(char *str, int istatus);
t_lst	*ft_add_end_lst_lst(t_lst *lst, t_lst *ptr);
char	*ft_strjoin_free(char *str1, char *str2);
int		ft_cnt_dbl_redir_str(char *str);
char	**ft_free_array(char **array);
void	ft_print_pipe_out(int fd_in);
t_acmd	*ft_util_add_pipe(t_acmd *acmd_data);
void	parent_signal(int isignal);
void	child_signal(int isignal);
char	*ft_free_str(char *str);
char	**ft_free_ptr_ptr(char **ptr);
int		ft_array_len(char **a);

// output
int		pipex(int argc, char **argv, t_data *data);
t_data	*single_cmd(char *str, t_data *data);
void	no_final_path(char **tab, char **paths, char *final_path);

// Temp
void	ft_put_array(char **array);

// readline
void	rl_replace_line(const char *c, int d);

// replace dollar
void	join_dollar(t_dlist *l, t_data *data);
int		print_dollar(char c);
void	check_join(t_dlist *list, char *str);
void	join_char(t_dlist *l, char c);
void	list_init(t_dlist *list, char *str, int state);
void	state_1(t_dlist *l);
char	*replace_dollar(char *str, int state, t_data *data);
void	if_question_mark(t_dlist *l, t_data *data);
char	*dollar_join_char(char *str, char c);

// free the str and put him null
void	free_str_and_null(char *str);

// utils 3
char	*ft_acmd_to_scmd(char **acmd);

#endif

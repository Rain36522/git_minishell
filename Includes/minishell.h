/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:21:32 by pudry             #+#    #+#             */
/*   Updated: 2023/11/16 10:09:09 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../ft_printf/ft_printf.h"
# include "../ft_printf/libft/libft.h"
# include <readline/readline.h>
# include <termios.h>
#include <fcntl.h>
# include <signal.h>

typedef struct s_incmd
{
	struct s_incmd	*next;
	char	*wrd;
	char	*filename;
}	t_incmd;

char	*cwd(void);
char	*find_hostname(char **env);
char	*ft_error_str(int icode);
int		ft_error_int(int icode);

// This functions are for taking the input
char	*get_cmd(char *prompt);
int		check_up_down_key(char *str);
void	ft_replace_line(char *prompt, char *s2);
int		find_str(char *str, char *to_find, int len);
char	*ft_skip_space_quotes(char *str);
t_incmd	*ft_lst_word(char *ptr, t_incmd *lst);
char	*ft_dbl_redi_in(char *str);
char	ft_is_string(char  ptr, char quote);
char	*ft_str_rplace_word(char *scmd, t_incmd *lst);
t_incmd	*ft_free_lst(t_incmd *lst, char *scmd);
int		ft_check_end_string(char ptr, char quote);
char	*ft_name_file(char *str);
int		ft_write_file(t_incmd *lst);
// ft_split
char	**ft_split_minishell(char const *s);
int	dup_str(char **tab, const char *s, int i);
int	len_dup_str(const char *s, int i);
int	spe_case_out_quotes(char c);
int	dup_pip_dir(char **tab, const char *s, int i, char c);
char	**free_split(char **tab);
int	str_nbr(char const *s, int i, int j);
int	skip_pipe_or_dir(const char *s, int i, char c);
int	check_spe_case(char c);
int	skip_until(const char *s, int i, char c);

#endif

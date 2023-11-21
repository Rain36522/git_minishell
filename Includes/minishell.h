/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:21:32 by pudry             #+#    #+#             */
/*   Updated: 2023/11/21 12:17:55 by pudry            ###   ########.fr       */
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

// Function test
void	ft_put_array(char **a);

// This funtion is for giving error message, exit programm
// or return NULL value needed
char	*ft_error_msg(int i);
int		ft_error_int(int icode, int iexit, char **array, char *str);
char	*ft_error_str(int icode, int iexit, char **array, char *str);
char	**ft_error_array(int icode, int iexit, char **array, char *str);


// This functions are for taking the input
char	**get_cmd(char *prompt);
char	**ft_make_dbl_redir(char **array);
t_incmd	*ft_free_lst(t_incmd *lst, char *scmd);
char	*ft_name_file(char *str);
int		ft_write_file(t_incmd *lst);

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
char	**from_quotes_to_wrds(char **tab);

// utils
char	*ft_give_prompte(char **env);
void	*ft_malloc(int isize, int ilength, char **array, char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:21:32 by pudry             #+#    #+#             */
/*   Updated: 2023/11/14 18:16:03 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../ft_printf/ft_printf.h"
# include "../ft_printf/libft/libft.h"
# include <readline/readline.h>
# include <termios.h>

typedef struct s_incmd
{
	struct s_incmd	*next;
	char	*wrd;
	char	*filename;
}	t_incmd;

char	*cwd(void);
char	*find_hostname(char **env);
char	*get_readline(int fd);
char	*ft_error_str(int icode);
int		ft_error_int(int icode);
char	*get_cmd(char *prompt);
int		check_up_down_key(char *str);
void	ft_replace_line(char *prompt, char *s2);
int		find_str(char *str, char *to_find, int len);
char	*ft_skip_space_quotes(char *str);
t_incmd	*ft_lst_word(char *ptr, t_incmd *lst);
char	*ft_dbl_redi_in(char *str);

#endif

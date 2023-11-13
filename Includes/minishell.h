/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:21:32 by pudry             #+#    #+#             */
/*   Updated: 2023/11/13 16:47:20 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../ft_printf/ft_printf.h"
# include "../ft_printf/libft/libft.h"
# include <readline/readline.h>
# include <termios.h>

char	*cwd(void);
char	*find_hostname(char **env);
char	*get_readline(int fd);
char	*ft_error_str(int icode);
char	*ft_error_int(int icode);
int		check_up_down_key(char *str);
char	*get_readline(int fd);
void	ft_replace_line(char *prompt, char *s2);

// typedef struct s_history
// {
// 	t_history	*next;
// 	t_history	*last;
// 	char	*cmd;
// }	t_history;

// typedef struct s_data
// {
// 	t_history	*hist_start;

// }	t_data;



#endif

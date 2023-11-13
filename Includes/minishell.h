/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:21:32 by pudry             #+#    #+#             */
/*   Updated: 2023/11/13 11:23:59 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include "../ft_printf/ft_printf.h"
# include "../ft_printf/libft/libft.h"
# include "../gnl/get_next_line.h"
# include <readline/readline.h>

char	*cwd(void);
char	*find_hostname(char **env);
char	*ft_error_str(int icode);
char	*ft_error_int(int icode);


#endif
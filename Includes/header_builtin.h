/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_builtin.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:35:26 by csil              #+#    #+#             */
/*   Updated: 2023/12/01 11:58:03 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_BUILTIN_H
# define HEADER_BUILTIN_H

# include "minishell.h"

// echo command
int		dollar_gestion(char *str, int i, char **envp);
int		is_n(char *str, int i);
int		print_backslash(char *str, int i);
void	not_found_str(char *str);
void	echo_cmd(char *str, char **envp);

// env command
void	env_cmd(char *str, char **envp);

// cd command
char	*simple_cd(char **envp);
int		check_cd(char *str);
void	cd_cmd(char **tab_cmd, char **envp);
void	init_cmd(char *str, char **envp);

// export command
char	**export_cmd(char **env, char **acmd);
void	ft_put_export(char **array);

// exit cmd
void	exit_cmd(char *str);
void	numeric_argument_required(char *str, char **tab);
void	too_many_args(char *str, char **tab);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_builtin.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:35:26 by csil              #+#    #+#             */
/*   Updated: 2023/12/08 09:34:43 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_BUILTIN_H
# define HEADER_BUILTIN_H

# include "minishell.h"

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

char	*cwd(char **env, char **array);
void	pwd(char **env, char **array);
char	*find_hostname(char **env);

// echo command
void	echo_cmd(char **tab);

// env command
void	env_cmd(char **tab, char **envp);

// Unset cmd
char	**unset_cmd(char **env, char **acmd);

// cd command
char	*simple_cd(char **envp);
int		check_cd(char *str);
void	cd_cmd(char **tab_cmd, char **envp);
void	init_cmd(char **tab, char **envp);

// export command
char	**export_cmd(char **env, char **acmd);
char	**ft_put_export(char **array, char **afree);
char	**ft_change_env(char *str, char **env);
int		ft_strcmp_egal(char *s1, char *s2);

// exit cmd
void	exit_cmd(char **tab);
void	too_many_args(char **tab);
void	numeric_argument_required(char **tab);

// utils
int		check_builtin(char *str, int iexit);
char	*builtin_strformatting(char **array);
char	**scmd_aformatting(char *str);

#endif

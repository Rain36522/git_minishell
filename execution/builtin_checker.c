/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:11:16 by csil              #+#    #+#             */
/*   Updated: 2023/12/01 13:57:08 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../Includes/header_builtin.h"
#include "../Includes/minishell.h"

// If that goes in one of those conditions, it should not
// "return" to the callong child process
// It should stop
void	builtin_checker(t_pipex *list, char **envp, t_data *data)
{
	char	*str;

	str = ft_acmd_to_scmd(list->cmd_args);
	if (!str)
	{
		ft_error_int(127, 1, NULL, NULL);
	}
	if (!ft_strncmp(str, "echo ", 5) || !ft_strncmp(str, "echo", 5))
		echo_cmd(str, envp, data);
	else if (!ft_strncmp(str, "cd ", 3) || !ft_strncmp(str, "cd", 3))
		init_cmd(str, envp);
	else if (!ft_strncmp(str, "env ", 4) || !ft_strncmp(str, "env", 4))
		env_cmd(str, envp);
	else if (!ft_strncmp(str, "export ", 7) || !ft_strncmp(str, "export", 7))
	{
		export_cmd(envp, str);
	}
	else if (!ft_strncmp(str, "unset ", 8) || !ft_strncmp(str, "unset ", 8))
		unset_cmd(envp, str);
	else if (!ft_strncmp(str, "exit ", 5) || !ft_strncmp(str, "exit", 5))
		exit_cmd(str);
	else
		return ;
	exit (0);
}

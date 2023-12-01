/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:11:16 by csil              #+#    #+#             */
/*   Updated: 2023/11/25 15:04:08 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "Includes/header_builtin.h"
#include "Includes/minishell.h"

// If that goes in one of those conditions, it should not
// "return" to the callong child process
// It should stop

void	builtin_checker_2(char *str, char **envp)
{
	if (ft_strncmp(str, "export", 7) == 0)
	{
		export_cmd(envp, str);
		exit;
	}
	//else if (ft_strncmp(str, "unset", 8) == 0)
	//	unset_cmd(str);
	//else if (ft_strncmp(str, "exit", 5) == 0)
	//	exit_cmd(str);
}

void	builtin_checker(t_pipex *list, char *str, char **tab_cmd, char **envp)
{
	char	**tmp;

	tmp = NULL;
	if (!str)
		ft_error_int(127, 1, NULL, NULL);
	else if (ft_strncmp(str, "echo", 5) == 0)
	{
		echo_cmd(str, envp);
		exit;
	}
	else if (ft_strncmp(str, "cd", 3) == 0)
	{
		init_cmd(str, envp);
		exit;
	}
	else if (ft_strncmp(str, "env", 4) == 0)
	{
		env_cmd(str, envp);
		exit;
	}
	else
		builtin_checker_2(str, envp);
}

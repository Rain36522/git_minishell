/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:11:16 by csil              #+#    #+#             */
/*   Updated: 2023/12/08 09:13:07 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../Includes/header_builtin.h"
#include "../Includes/minishell.h"

// If that goes in one of those conditions, it should not
// "return" to the callong child process
// It should stop
void	builtin_checker(t_pipex *list, char **envp)
{
	int		i;

	i = check_builtin(list->cmd_args[0], 0);
	if (i == 127)
		free_all_exit(list, 127);
	else if (i == 1)
		echo_cmd(list->cmd_args);
	else if (i == 2)
		cd_cmd(list->cmd_args, envp);
	else if (i == 3)
		env_cmd(list->cmd_args, envp);
	else if (i == 4)
		export_cmd(envp, list->cmd_args);
	else if (i == 5)
		unset_cmd(envp, list->cmd_args);
	else if (i == 6)
		exit_cmd(list->cmd_args);
	else if (i == 7)
		pwd(envp, list->cmd_args);
	else
		return ;
	exit (0);
}

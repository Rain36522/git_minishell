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

void	builtin_checker(char *str, char **tab_cmd)
{
	if (ft_strncmp(str, "echo", 5) == 0)
		echo_cmd(tab_cmd);
	else if (ft_strncmp(str, "cd", 3) == 0)
		cd_cmd(tab_cmd);
	else if (ft_strncmp(str, "env", 4) == 0)
		env_cmd(tab_cmd);
	else if (ft_strncmp(str, "export", 7) == 0)
		export_cmd(tab_cmd);
	else if (ft_strncmp(str, "unset", 8) == 0)
		unset_cmd(tab_cmd);
	else if (ft_strncmp(str, "exit", 5) == 0)
		exit_cmd(tab_cmd);
}

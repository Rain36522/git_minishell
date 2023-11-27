/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:34:07 by csil              #+#    #+#             */
/*   Updated: 2023/11/25 15:04:13 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirection_checker(t_pipex *list, char *str, char **tab_cmd)
{
	if (ft_strncmp(str, '<', 1) == 0)
		redir_cmd(tab_cmd);
	else if (ft_strncmp(str, '<', 1) == 0)
		redir_cmd(tab_cmd);
	else if (ft_strncmp(str, "<<", 1) == 0)
		redir_cmd(tab_cmd);
}

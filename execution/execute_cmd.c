/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:35:20 by csil              #+#    #+#             */
/*   Updated: 2023/12/05 14:13:43 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// found the env PATH= line
char	*env_path(char **envp)
{
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (envp[i])
		return (envp[i] + 5);
	else
		return (NULL);
}

// join the valid path (env) + arg[0] cmd and return it
char	*create_final_path(t_pipex *list, char **paths, char *arg)
{
	int		i;
	char	*final_path;
	char	*tmp;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
			free_all_exit(list, 12);
		final_path = ft_strjoin(tmp, arg);
		if (!final_path)
			free_all_exit(list, 12);
		tmp = ft_free_str(tmp);
		if (access(final_path, F_OK) == 0)
		{
			return (final_path);
		}
		final_path = ft_free_str(final_path);
		i++;
	}
	return (NULL);
}

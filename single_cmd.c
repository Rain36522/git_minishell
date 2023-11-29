/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:56:07 by cduffaut          #+#    #+#             */
/*   Updated: 2023/11/29 09:58:52 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/minishell.h"
#include "multi_pipex/pipex.h"

//    Else: he execute the cmd (path + argv[0], argv, envp)
char	*join_path(char **paths, char **args, int i)
{
	char	*final_path;
	char	*tmp;

	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
        {
            ft_free_array(args);
			ft_error_array(12, 1, paths, NULL);
        }
        final_path = ft_strjoin(tmp, args[0]);
        free(tmp);
		if (!final_path)
        {
	        ft_free_array(args);
			ft_error_array(12, 1, paths, NULL);
        }
		if (access(final_path, F_OK) == 0)
			return (final_path);
		free(final_path);
		i++;
	}
	return (NULL);
}

void    not_builtin(char **tab, char **envp)
{
    char    **paths;
    char    *final_path;
    char    *pre_path;

    pre_path = env_path(envp);
    paths = ft_split(pre_path, ':');
    if (!paths)
        ft_error_array(12, 1, tab, NULL);
    final_path = join_path(paths, tab, 0);
    if (!final_path)
    {
        ft_putstr_fd(tab[0], 2);
        ft_putstr_fd(": command not foud\n", 2);
    }
    ft_free_array(paths);
    if (execve(final_path, tab, envp) == -1)
    {
        //ft_error_array(errno, 0, tab, final_path); // free la tab + ft error paul
    }
}

void    single_cmd(char **tab_cmd, char **envp)
{
    /*if (ft_strncmp(tab_cmd[0], "echo", 5) == 0)
		echo_cmd(tab_cmd);
	else if (ft_strncmp(tab_cmd[0], "cd", 3) == 0)
		cd_cmd(tab_cmd);
	else if (ft_strncmp(tab_cmd[0], "env", 4) == 0)
		env_cmd(tab_cmd);
	else if (ft_strncmp(tab_cmd[0], "export", 7) == 0)
		export_cmd(tab_cmd);
	else if (ft_strncmp(tab_cmd[0], "unset", 8) == 0)
		unset_cmd(tab_cmd);
	else if (ft_strncmp(tab_cmd[0], "exit", 5) == 0)
		exit_cmd(tab_cmd);
    else*/
        not_builtin(tab_cmd, envp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:56:07 by cduffaut          #+#    #+#             */
/*   Updated: 2023/12/02 14:03:03 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

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
			ft_error_int(12, 1, paths, NULL);
		}
		final_path = ft_strjoin(tmp, args[0]);
		free(tmp);
		if (!final_path)
		{
			ft_free_array(args);
			ft_error_int(12, 1, paths, NULL);
		}
		if (access(final_path, F_OK) == 0)
			return (final_path);
		free(final_path);
		i++;
	}
	return (NULL);
}

static void	no_final_path(char **tab, char **paths, char *final_path)
{
	ft_putstr_fd(tab[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	ft_free_array(paths);
	ft_error_int(127, 0, tab, final_path);
}

void	not_builtin(char **tab, char **envp)
{
	char	**paths;
	char	*final_path;
	char	*pre_path;

	pre_path = env_path(envp);
	if (pre_path)
	{
		paths = ft_split(pre_path, ':');
		if (!paths)
			ft_error_int(12, 1, tab, NULL);
	}
	else
		paths = NULL;
	final_path = join_path(paths, tab, 0);
	if (!final_path)
		no_final_path(tab, paths, final_path);
	ft_free_array(paths);
	if (execve(final_path, tab, envp) == -1)
	{
		ft_free_array(envp);
		ft_error_int(errno, 1, tab, final_path);
	}
}

static void	fork_not_builtin(char **tab, char **envp)
{
	pid_t	pid;
	int		istatus;

	pid = fork();
	if (pid < 0)
		ft_error_ptr(9, 1, tab, NULL);
	else if (pid == 0)
		not_builtin(tab, envp);
	else
	{
		waitpid(pid, &istatus, 0);
		if (WEXITSTATUS(istatus) != 0)
			ft_error_child(WEXITSTATUS(istatus), tab, NULL, NULL);
	}
}

char	**single_cmd(char *str, char **envp)
{
	char	**tmp;

	tmp = NULL;
	if (!str)
		ft_error_int(127, 1, NULL, NULL);
	else if (!ft_strncmp(str, "echo ", 5) || !ft_strncmp(str, "echo", 5))
		echo_cmd(str, envp);
	else if (!ft_strncmp(str, "cd ", 3) || !ft_strncmp(str, "cd", 3))
		init_cmd(str, envp);
	else if (!ft_strncmp(str, "env ", 4) || !ft_strncmp(str, "env", 4))
		env_cmd(str, envp);
	else if (!ft_strncmp(str, "export ", 7) || !ft_strncmp(str, "export", 7))
		envp = export_cmd(envp, str);
	//else if (ft_strncmp(str, "unset ", 6) || !ft_strncmp(str, "unset", 6))
	//	envp = unset_cmd(str);
	else if (!ft_strncmp(str, "exit ", 5) || !ft_strncmp(str, "exit", 5))
		exit_cmd(str);
	else
	{
		ft_printf("not builtin\n");
		tmp = ft_split (str, ' ');
		if (!tmp)
			ft_error_int(12, 1, NULL, str);
		fork_not_builtin(tmp, envp);
		if (tmp)
		{
			free(tmp);
			tmp = NULL;
		}
	}
	return (envp);
}

/*int     main(int argc, char **argv, char **envp)
{
    (void) argc;
    single_cmd(argv + 1, envp);
    return (0);
}*/

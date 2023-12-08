/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:56:07 by cduffaut          #+#    #+#             */
/*   Updated: 2023/12/08 10:03:14 by pudry            ###   ########.fr       */
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
	if (execve(final_path, tab, envp) == -1)
	{
		ft_putstr_fd("71\n", 2);
		ft_free_array(envp);
		ft_error_int(150, 1, NULL, final_path);
	}
}

static int	fork_not_builtin(char **tab, t_data *data)
{
	int	i;

	i = 0;
	data->pid = fork();
	if (data->pid < 0)
		ft_error_ptr(9, 1, tab, NULL);
	else if (data->pid == 0)
		not_builtin(tab, data->env);
	else
	{
		waitpid(data->pid, &i, 0);
		if (WEXITSTATUS(i) != 0)
		{
			ft_error_child(i, NULL, NULL, NULL);
			return (1);
		}	
	}
	return (0);
}

static t_data	*ft_make_builtin(char **array, t_data *data)
{
	int		i;

	i = check_builtin(array[0], 0);
	if (i == 1)
		echo_cmd(array);
	else if (i == 2)
		cd_cmd(array, data->env);
	else if (i == 3)
		env_cmd(array, data->env);
	else if (i == 4)
		data->env = export_cmd(data->env, array);
	else if (i == 5)
		data->env = unset_cmd(data->env, array);
	else if (i == 6)
		exit_cmd(array);
	else if (i == 7)
		pwd(data->env, array);
	return (data);
}

t_data	*single_cmd(char *str, t_data *data)
{
	char	**tmp;

	tmp = scmd_aformatting(str);
	if (!tmp)
		ft_error_int(12, 0, NULL, str);
	if (check_builtin(tmp[0], 0) > 0 && check_builtin(tmp[0], 0) != 127)
		return (ft_make_builtin(tmp, data));
	else if (check_builtin(tmp[0], 0) == 0)
	{
		data->iexit = fork_not_builtin(tmp, data);
		if (tmp)
			tmp = ft_free_array(tmp);
	}
	return (data);
}

/*int     main(int argc, char **argv, char **envp)
{
    (void) argc;
    single_cmd(argv + 1, envp);
    return (0);
}*/

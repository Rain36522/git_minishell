/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:22:52 by csil              #+#    #+#             */
/*   Updated: 2023/12/08 11:01:08 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_dup2(t_pipex *list, int input, int output)
{
	if (dup2(input, STDIN_FILENO) < 0)
		free_all_exit(list, errno);
	if (dup2(output, STDOUT_FILENO) < 0)
		free_all_exit(list, errno);
}

void	wait_child_process(t_pipex *list, t_data *data)
{
	int		i;

	i = 0;
	while (i < list->cmd_nbr)
	{
		waitpid(list->pid_array[i], &data->iexit, 0);
		if (WIFEXITED(data->iexit))
		{
			list->exit_value = WEXITSTATUS(data->iexit);
		}
		else if (WIFSIGNALED(data->iexit))
		{
			list->exit_value = WTERMSIG(data->iexit);
		}
		else
			list->exit_value = data->iexit;
		i++;
	}
}

void	print_tab_term_2(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_putstr_fd(tab[i], 2);
		i++;
	}
}

// init the tab of pipes (int *)
void	create_pipes(t_pipex *list)
{
	int		i;

	i = 0;
	while (i < list->cmd_nbr - 1)
	{
		pipe(list->pipe + (i * 2));
		if (list->pipe + (i * 2) < 0)
		{
			errno = EFAULT;
			free_all_exit(list, list->exit_value);
		}
		i++;
	}
}

// In Dir and Builtin process need to be finished by an exit
void	child_process(char **argv, t_data *data, t_pipex l)
{
	l.pid_array[l.index] = fork();
	if (l.pid_array[l.index] == 0)
	{
		if (l.index == 0)
			ft_dup2(&l, l.input, l.pipe[l.index * 2 + 1]);
		else if (l.index == (l.cmd_nbr - 1))
			ft_dup2(&l, l.pipe[l.index * 2 - 2], 1);
		else
			ft_dup2(&l, l.pipe[l.index * 2 - 2], l.pipe[l.index * 2 + 1]);
		l.cmd_args = scmd_aformatting(argv[l.index + 1]);
		if (!l.cmd_args)
			free_all_exit(&l, 12);
		close_all_pipes(&l);
		ft_make_redir(l.cmd_args);
		builtin_checker(&l, data->env);
		l.cmd = create_final_path(&l, l.cmd_path, l.cmd_args[0]);
		if (!l.cmd)
			cmd_not_found(&l);
		if (execve(l.cmd, l.cmd_args, data->env) == -1)
		{
			free_all_exit (&l, l.exit_value);
		}
		exit(0);
	}
}

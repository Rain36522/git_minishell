/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:22:52 by csil              #+#    #+#             */
/*   Updated: 2023/11/26 20:58:32 by csil             ###   ########.fr       */
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

void	wait_child_process(t_pipex *list)
{
	int		i;
	int		wait_v;

	i = 0;
	wait_v = 0;
	while (i < list->cmd_nbr)
	{
		waitpid(list->pid_array[i], &wait_v, 0);
		if (WIFEXITED(wait_v))
		{
			list->exit_value = WEXITSTATUS(wait_v);
		}
		else if (WIFSIGNALED(wait_v))
		{
			list->exit_value = -WTERMSIG(wait_v);
		}
		else
			list->exit_value = wait_v;
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
void	child_process(char **argv, char **envp, t_pipex l)
{
	l.pid_array[l.index] = fork();
	if (l.pid_array[l.index] == 0)
	{
		if (l.index == 0)
			ft_dup2(&l, l.input, l.pipe[l.index * 2 + 1]);
		else if (l.index == (l.cmd_nbr - 1))
			ft_dup2(&l, l.pipe[l.index * 2 - 2], l.output);
		else
			ft_dup2(&l, l.pipe[l.index * 2 - 2], l.pipe[l.index * 2 + 1]);
		close_all_pipes(&l);
		l.cmd_args = ft_split(argv[l.index + 1], ' ');
		if (!l.cmd_args)
			free_all_exit(&l, 12);
		l.cmd = create_final_path(&l, l.cmd_path, l.cmd_args[0]);
		if (!l.cmd)
			cmd_not_found(&l);
		//builtin_checker(&l, l.cmd_args[0], l.cmd_args);
		//redirection_checker(&l, l.cmd_args[0], l.cmd_args);
		if (execve(l.cmd, l.cmd_args, envp) == -1)
		{
			free_all_exit (&l, l.exit_value);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:44:24 by csil              #+#    #+#             */
/*   Updated: 2023/12/08 09:19:20 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// print in the 2 fd error nbr arg 
void	wrong_args_number(void)
{
	ft_putstr_fd("Error: wrong numbers of arguments\n", 2);
	exit(EXIT_FAILURE);
}

/*
	si message d'erreur à indiquer : créer fonction putstr_fd
	qui affiche le str en par sur le terminal 2

	Ou imprimer mess d'erreur direct dans le code;
*/

void	cmd_not_found(t_pipex *list)
{
	ft_putstr_fd("command not found: ", 2);
	ft_putstr_fd(list->cmd_args[0], 2);
	ft_putstr_fd("\n", 2);
	errno = 127;
	free_all_exit(list, errno);
}

// close all pipes from the tab
void	close_all_pipes(t_pipex *list)
{
	int		i;

	i = 0;
	while (i < list->pipe_nbr)
	{
		close (list->pipe[i]);
		i++;
	}
}

// free all of the malloced content during the prog
// and exit error code
void	free_all_exit(t_pipex *list, int nbr)
{
	close_all_pipes(list);
	close(list->output);
	if (list->pipe)
	{
		free (list->pipe);
		list->pipe = NULL;
	}
	if (list->pid_array)
	{
		free (list->pid_array);
		list->pid_array = NULL;
	}
	if (list->cmd_path)
		list->cmd_path = ft_free_array(list->cmd_path);
	if (list->cmd_args)
		list->cmd_args = ft_free_array(list->cmd_args);
	if (list->cmd)
		list->cmd = ft_free_str(list->cmd);
	if (nbr == 0)
		return ;
	else
		ft_error_msg(nbr);
}

// free tab and all of the content in tab
void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csil <csil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:15:58 by csil              #+#    #+#             */
/*   Updated: 2023/11/26 21:09:33 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

// open and check error for the input file
void	set_infile(char **argv, t_pipex *list)
{
	int		infile;

	infile = ft_atoi(argv[0]);
	list->input = infile;
}

// open and check error for the output file
// pour handle le cas output : >> file 
// open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
void	set_outfile(int argc, char **argv, t_pipex *list)
{
	int		outfile;

	outfile = ft_atoi(argv[argc - 1]);
	list->output = outfile;
}

void	init_multi_pipex(t_pipex *list, int argc, char **argv)
{
	set_infile(argv, list);
	set_outfile(argc, argv, list);
	list->cmd_nbr = argc - 2;
	list->pipe_nbr = (2 * (list->cmd_nbr - 1));
	list->pipe = malloc(sizeof(int) * list->pipe_nbr);
	if (!list->pipe)
		free_all_exit(list, 12);
	list->pid_array = malloc(sizeof(pid_t) * list->cmd_nbr);
	if (!list->pid_array)
		free_all_exit(list, 12);
}

// main function of multipipex
int	pipex(int argc, char **argv, char **envp)
{
	t_pipex	list;

	list = (t_pipex){};
	if (argc < 4)
		wrong_args_number();
	init_multi_pipex(&list, argc, argv);
	list.env_path = env_path(envp);
	list.cmd_path = ft_split(list.env_path, ':');
	if (!list.cmd_path)
		free_all_exit(&list, 12);
	create_pipes(&list);
	list.index = -1;
	while (++list.index < list.cmd_nbr)
		child_process(argv, envp, list);
	close_all_pipes(&list);
	wait_child_process(&list);
	free_all_exit(&list, list.exit_value);
	return (list.exit_value);
}

// tester for multipipex
/*int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	char *tab[] = {"0", "echo Hello World", "zbeb", "echa ZbebZbeb", "1"};
	pipex(5, tab, envp);
	return (0);
}*/

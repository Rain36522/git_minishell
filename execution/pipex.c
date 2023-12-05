/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:15:58 by csil              #+#    #+#             */
/*   Updated: 2023/12/02 14:00:00 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

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
int	pipex(int argc, char **argv, t_data *data)
{
	t_pipex	list;

	list = (t_pipex){};
	if (argc < 4)
		wrong_args_number();
	list.argv = argv;
	list.envp = data->env;
	init_multi_pipex(&list, argc, argv);
	list.env_path = env_path(data->env);
	list.cmd_path = ft_split(list.env_path, ':');
	if (!list.cmd_path)
		free_all_exit(&list, 12);
	create_pipes(&list);
	list.index = -1;
	while (++list.index < list.cmd_nbr)
		child_process(argv, data, list);
	close_all_pipes(&list);
	wait_child_process(&list, data);
	free_all_exit(&list, list.exit_value);
	return (list.exit_value);
}

// tester for multipipex
/*int	main(int argc, char **argv, char **envp)
{
	int		fd[2];

	sleep(13);
	(void) argc;
	(void) argv;
	if (pipe(fd) < 0)
		exit(9);
	char *tab[] = {ft_itoa(fd[0]), "< pipex.c", "cat", ft_itoa(fd[1])};
	pipex(5, tab, envp);
	return (0);
}*/

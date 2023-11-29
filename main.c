/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:52:43 by pudry             #+#    #+#             */
/*   Updated: 2023/11/28 15:04:45 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/minishell.h"
#include <readline/history.h>
#include <stdio.h>

int	main(int argc, char **argv, char **env)
{
	int		fd;
	int		i;
	int		*pipe_fd;
	char	*prompt;
	char	buf[11];
	t_acmd	*cmd_data;
	char	**array;

	argc += 0;
	argv += 0;
	i = 0;
	while (i == 0)
	{
		prompt = ft_give_prompte(env);
		cmd_data = get_cmd(prompt);
		if (cmd_data)
		{
			pipex(cmd_data->isize, cmd_data->array, env);
			ft_print_pipe_out(cmd_data->fd_pipe[0], cmd_data->fd_pipe[1]);
		}
		free(prompt);
	}
	return (0);
}

// int	main(int argc, char **argv, char **env)
// {
// 	char *tab[] = {"0", "< Makefile", "cat", "1", NULL};

// 	pipex(4, tab, env);

// 	return (0);
// }

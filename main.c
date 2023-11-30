/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:52:43 by pudry             #+#    #+#             */
/*   Updated: 2023/11/30 10:00:12 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/minishell.h"
#include <readline/history.h>
#include <stdio.h>

int	main(int argc, char **argv, char **env)
{
	int		i;
	char	*prompt;
	t_acmd	*cmd_data;

	argc += 0;
	argv += 0;
	i = 0;
	signal(SIGINT, parent_signal);
	while (i == 0)
	{
		prompt = ft_give_prompte(env);
		cmd_data = get_cmd(prompt);
		ft_put_array(cmd_data->array);
		ft_printf("CC\n");
		if (cmd_data)
		{
			pipex(cmd_data->isize, cmd_data->array, env);
			ft_print_pipe_out(cmd_data->fd_pipe[0]);
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

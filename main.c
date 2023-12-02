/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:52:43 by pudry             #+#    #+#             */
/*   Updated: 2023/12/02 14:12:49 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/minishell.h"
#include <readline/history.h>
#include <stdio.h>

static char	**dup_env(char **env)
{
	char	**env2;
	int		i;

	i = 0;
	while (env[i])
		i ++;
	env2 = (char **) malloc(sizeof(char *) * (i + 1));
	env2[i] = NULL;
	i = 0;
	while (env[i])
	{
		env2[i] = ft_strdup(env[i]);
		if (!env[i])
		{
			free(env2);
			ft_error_ptr(12, 1, NULL, NULL);
		}
		i ++;
	}
	return (env2);
}

static char	**execute(t_acmd *cmd_data, char **env)
{
	if (cmd_data->array[1])
	{
		pipex(cmd_data->isize, cmd_data->array, env);
		ft_print_pipe_out(cmd_data->fd_pipe[0]);
	}
	else
	{
		env = single_cmd(cmd_data->array[0], env);
	}
	return (env);
}

int	main(int argc, char **argv, char **env)
{
	int		i;
	char	*prompt;
	t_acmd	*cmd_data;

	argc += 0;
	argv += 0;
	i = 0;
	env = dup_env(env);
	signal(SIGINT, parent_signal);
	while (i == 0)
	{
		prompt = ft_give_prompte(env);
		cmd_data = get_cmd(prompt, env);
		if (cmd_data)
			env = execute(cmd_data, env);
		if (cmd_data->array)
		{
			free(cmd_data->array);
			cmd_data->array = NULL;
		}
		if (cmd_data)
		{
			free(cmd_data);
			cmd_data = NULL;
		}
		if (prompt)
		{
			free (prompt);
			prompt = NULL;
		}
	}
	return (0);
}

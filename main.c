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

static char	**execute(t_acmd *cmd_data, t_data *data)
{
	if (cmd_data->array[1])
	{
		pipex(cmd_data->isize, cmd_data->array, data);
		ft_print_pipe_out(cmd_data->fd_pipe[0]);
	}
	else
	{
		data->env = single_cmd(cmd_data->array[0], data);
	}
	printf ("execute 52\n");
	return (data->env);
}

void	free_str_and_null(char *str)
{
	free(str);
	str = NULL;
}

void	free_list_and_null(t_acmd *list)
{
	free(list);
	list = NULL;
}

int	main(int argc, char **argv, char **env)
{
	char	*prompt;
	t_acmd	*cmd_data;
	t_data	data;

	argv += argc;
	data.env = dup_env(env);
	signal(SIGINT, parent_signal);
	while (1)
	{
		printf ("main 79\n");
		prompt = ft_give_prompte(data.env);
		printf ("main 81\n");
		cmd_data = get_cmd(prompt, &data);
		printf ("main 83\n");
		if (cmd_data)
		{
			printf ("main 86\n");
			ft_put_array(cmd_data->array);
			printf ("main 88\n");
			env = execute(cmd_data, &data);
			printf ("main 90\n");
			// if (cmd_data->array)
			// 	ft_free_array(cmd_data->array);
			printf ("main 93\n");
			free_list_and_null(cmd_data);
			printf ("main 95\n");
		}
		printf ("main 97\n");
		if (prompt)
			free_str_and_null(prompt);
		printf ("main 100\n");
	}
	return (0);
}

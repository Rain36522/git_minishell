/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:52:43 by pudry             #+#    #+#             */
/*   Updated: 2023/12/08 11:02:11 by pudry            ###   ########.fr       */
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

static void	execute(t_acmd *cmd_data, t_data *data)
{
	if (cmd_data->array[1])
	{
		data->iexit = pipex(cmd_data->isize, cmd_data->array, data);
		close(cmd_data->fd_pipe[0]);
	}
	else
	{
		data = single_cmd(cmd_data->array[0], data);
	}
	if (cmd_data->array)
		cmd_data->array = ft_free_array(cmd_data->array);
	free_list_and_null(cmd_data);
}

int	main(int argc, char **argv, char **env)
{
	char	*prompt;
	t_acmd	*cmd_data;
	t_data	data;

	data = (t_data){};
	argv += argc;
	data.env = dup_env(env);
	signal(SIGINT, parent_signal);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		prompt = ft_give_prompte(data.env);
		cmd_data = get_cmd(prompt, &data);
		if (cmd_data)
			execute(cmd_data, &data);
		else
			data.iexit = 1;
		if (prompt)
			prompt = ft_free_str(prompt);
		data.imem_exit = data.iexit;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:19:01 by cduffaut          #+#    #+#             */
/*   Updated: 2023/12/01 14:04:49 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../Includes/minishell.h"
#include "../Includes/header_builtin.h"

int	dollar_gestion(char *str, int i, char **envp)
{
	int		j;
	int		k;
	int		start;

	start = i;
	k = 0;
	j = 0;
	while (str[i] && str[i] != 32 && str[i] != '\'' && str[i] != '\"')
		i++;
	while (envp[j])
	{
		if (ft_strncmp(envp[j], str + start + 1, i - start - 1) == 0)
		{
			while (envp[j][k] && envp[j][k] != '=')
				k++;
			printf ("%s", envp[j] + k + 1);
			return (i);
		}
		j++;
		k = 0;
	}
	return (i);
}

int	is_n(char *str, int i)
{
	int		backup;

	if (str[i] != 32)
		return (-1);
	i++;
	backup = i;
	if (str[i] == '-' && str[i + 1] == 'n')
	{
		i++;
		while (str[i] && str[i] == 'n')
			i++;
		if (str[i] && str[i] != 32)
			return (backup);
		return (i + 1);
	}
	return (i);
}

// return 1 if -n, and 0 if no n
int	print_backslash(char *str, int i)
{
	if (str[i] == '-' && str[i + 1] == 'n')
	{
		i++;
		while (str[i] && str[i] == 'n')
			i++;
		if (str[i] && str[i] != 32)
			return (0);
		return (1);
	}
	return (0);
}

// str to return if cmd not found
// return str from start until 32 or \n
void	not_found_str(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != 32)
	{
		printf ("%c", str[i]);
		i++;
	}
	printf(": command not found\n");
	exit (127);
}

// display text following w \n if no -n
void	echo_cmd(char *str, char **envp)
{
	int		i;
	int		n;

	i = 4;
	n = is_n(str, i);
	if (n == -1)
		not_found_str(str);
	i = n;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] && str[i] != '\'')
				printf ("%c", str[i++]);
			if (str[i])
				i++;
		}
		else if (str[i] == '$')
			i = dollar_gestion(str, i, envp);
		else
			printf("%c", str[i++]);
	}
	if (print_backslash(str, 5) == 0)
		printf ("\n");
}

/*int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;

	echo_cmd("echo '$USER' $USER", envp);
	return (0);
}*/

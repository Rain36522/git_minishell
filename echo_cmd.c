/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:19:01 by cduffaut          #+#    #+#             */
/*   Updated: 2023/11/25 20:38:05 by csil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "Includes/minishell.h"
#include "Includes/header_builtin.h"

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
	exit (-1); // code erreur
}

/*
 *Je dois rajouter pour chaque special case loption dollar
 * */

// display text following w \n if no -n
int	echo_cmd(char *str, char **envp)
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
		if (str[i] && str[i] == '\'')
			i = print_until(str, i + 1, '\'', envp);
		else if (str[i] && str[i] == '\"')
			i = print_until(str, i + 1, '\"', envp);
		while (str[i] && str[i] != '\'' && str[i] != '\"')
		{
			if (str[i] == '$')
				i = dollar_gestion(str, i, envp); // doit ramener sur le char apres la var dollar
			printf ("%c", str[i++]);
		}
	}
	if (print_backslash(str, 5) == 0)
		printf ("\n");
	return (0);
}

/*int	main(int argc, char **argv, char **envp)
{
	(void) argc;

	//echo_cmd("echo  coucou\"$OLDPWD\"greiohg \\nbangala", envp);
	echo_cmd(argv[1], envp);
	return (0);
}*/

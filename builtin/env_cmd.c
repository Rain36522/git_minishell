/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:45:41 by cduffaut          #+#    #+#             */
/*   Updated: 2023/11/24 18:13:06 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "Includes/minishell.h"

void	env_cmd(char *str, char **envp)
{
	int		i;

	i = 0;
	if (str && ft_strncmp(str, "env", 3) != 0)
	{
		printf ("%s", str);
		exit (-1); // error code
	}
	while (envp[i])
	{
		printf ("%s\n", envp[i]);
		i++;
	}
}

/*int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	env_cmd(argv[1], envp);
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:45:41 by cduffaut          #+#    #+#             */
/*   Updated: 2023/12/01 14:05:03 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../Includes/minishell.h"

void	env_cmd(char *str, char **envp)
{
	int		i;

	i = 0;
	if (str && ft_strncmp(str, "env", 4) != 0)
	{
		ft_error_int(127, 0, NULL, str);
		return ;
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

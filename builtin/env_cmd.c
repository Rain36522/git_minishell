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

// receive in arg a tab of the cmd
void	env_cmd(char **tab, char **envp)
{
	int		i;

	i = 0;
	if (tab[1])
	{
		ft_error_int(2, 0, tab, NULL);
		return ;
	}
	while (envp[i])
	{
		printf ("%s\n", envp[i]);
		i++;
	}
	tab = ft_free_array(tab);
	exit(0);
}

/*int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	env_cmd(argv + 1, envp);
	return (0);
}*/

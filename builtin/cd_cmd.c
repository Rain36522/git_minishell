/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:47:09 by cduffaut          #+#    #+#             */
/*   Updated: 2023/12/01 14:05:08 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

// cd simple cmd
char	*simple_cd(char **envp)
{
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "HOME=", 5) != 0)
		i++;
	return (envp[i] + 5);
}

// check if the first arg is well CD
int	check_cd(char *str)
{
	if (str[0] == 'c')
		if (str[1] == 'd')
			if (str[2] == ' ' || str[2] == '\0')
				return (1);
	return (0);
}

void	cd_cmd(char **tab_cmd, char **envp)
{
	if (check_cd(tab_cmd[0]) == 0)
		ft_error_int(127, 0, tab_cmd, NULL);
	else if (!tab_cmd[1])
	{
		if (chdir(simple_cd(envp)) != 0)
		{
			ft_error_int(127, 0, tab_cmd, NULL);
		}
		else
			tab_cmd = ft_free_array(tab_cmd);
	}
	else
	{
		if (chdir(tab_cmd[1]) != 0)
		{
			ft_error_int(127, 0, tab_cmd, NULL);
			return ;
		}
		else
			tab_cmd = ft_free_array(tab_cmd);
	}
}

void	init_cmd(char **tab, char **envp)
{
	if (!tab)
		ft_error_int(12, 1, NULL, NULL);
	cd_cmd(tab, envp);
	if (tab)
		tab = ft_free_array(tab);
}

// Exit code 127 is not currently relate to
// command not found
/*int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;

	char *tab = ft_strdup("cd uti*");
	init_cmd(tab, envp);
	return (0);
}*/

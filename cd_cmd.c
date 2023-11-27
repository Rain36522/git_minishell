/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:47:09 by cduffaut          #+#    #+#             */
/*   Updated: 2023/11/27 11:03:12 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/minishell.h"
#include "multi_pipex/pipex.h"

// cd simple cmd
char	*simple_cd(char **envp)
{
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "HOME=", 5) != 0)
		i++;
	printf ("cmd to exec %s\n", envp[i] + 5);
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
	char	*line_path;
	char	**tab_l_path;
	
	if (check_cd(tab_cmd[0]) == 0)
		ft_error_msg(201);
	if (!tab_cmd[1])
	{
		if (chdir(simple_cd(envp)) != 0)
		{
			printf ("path not found\n");
			exit (1);
		}
		exit (0);
	}
	line_path = env_path(envp);
	if (!line_path)
		ft_error_str(12, 1, NULL, line_path);
	tab_l_path = ft_split(line_path, ' ');
		ft_error_str(12, 1, tab_l_path, line_path);
}


// you in arg the tab of the split ' ' cmd
int	main(int argc, char **argv, char **envp)
{
	(void) argc;

	cd_cmd(argv + 1, envp);
	return (0);
}

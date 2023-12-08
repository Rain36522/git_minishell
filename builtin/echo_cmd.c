/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:19:01 by cduffaut          #+#    #+#             */
/*   Updated: 2023/12/08 09:22:50 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../Includes/minishell.h"
#include "../Includes/header_builtin.h"

static int	check_n(char *str)
{
	int		i;

	i = 1;
	if (str[0] != '-')
		return (0);
	if (str[i] != 'n')
		return (0);
	while (str[i] && str[i] == 'n')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	echo_cmd(char **tab)
{
	int		n;
	int		i;

	i = 1;
	if (!tab[1])
	{
		printf ("\n");
		tab = ft_free_array(tab);
		return ;
	}
	n = check_n(tab[1]);
	if (n == 1)
		i = 2;
	while (tab[i])
	{
		printf ("%s", tab[i]);
			i++;
		if (tab[i])
			printf (" ");
	}
	if (n == 0)
		printf ("\n");
	tab = ft_free_array(tab);
}

/*int	main(int argc, char **argv)
{
	(void) argc;

	echo_cmd(argv + 1);
	return (0);
}*/
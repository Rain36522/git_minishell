/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:33:50 by cduffaut          #+#    #+#             */
/*   Updated: 2023/12/08 09:21:56 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"
#include "../Includes/header_builtin.h"

static int	non_numeric(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

static int	tab_size(char **tab)
{
	int		i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
	{
		i++;
	}
	return (i);
}

static void	exit_classic(char **tab)
{
	tab = ft_free_array(tab);
	exit (1);
}

void	exit_cmd(char **tab)
{
	int		e_code;

	printf("exit\n");
	if (tab[1] && non_numeric(tab[1]) == 1)
		numeric_argument_required(tab);
	else if (tab_size(tab) >= 3)
	{
		too_many_args(tab);
		return ;
	}
	else if (tab_size(tab) == 1)
		exit_classic(tab);
	else
	{
		e_code = ft_atoi(tab[1]);
		tab = ft_free_array(tab);
		exit (e_code);
	}
}

/*int	main(void)
{
	char *str = ft_strdup("exit   12a3    ");
	exit_cmd(str);
	return (0);
}*/

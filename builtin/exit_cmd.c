/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:33:50 by cduffaut          #+#    #+#             */
/*   Updated: 2023/12/01 14:04:40 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

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

static void	exit_classic(char *str, char **tab)
{
	if (str)
	{
		free (str);
		str = NULL;
	}
	ft_free_array(tab);
	printf("exit\n");
	exit (0);
}

void	exit_cmd(char *str)
{
	int		e_code;
	char	**tab;

	if (!str)
		exit (1);
	tab = ft_split(str, ' ');
	if (!tab)
		ft_error_int(12, 1, NULL, str);
	else if (tab_size(tab) >= 3)
	{
		too_many_args(str, tab);
	}
	else if (tab_size(tab) == 1)
		exit_classic(str, tab);
	else if (non_numeric(tab[1]) == 1)
		numeric_argument_required(str, tab);
	else
	{
		e_code = ft_atoi(tab[1]);
		free(str);
		str = NULL;
		ft_free_array(tab);
		printf("exit\n");
		exit (e_code);
	}
}

/*int	main(void)
{
	char *str = ft_strdup("exit   12a3    ");
	exit_cmd(str);
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cmd_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:12:01 by cduffaut          #+#    #+#             */
/*   Updated: 2023/11/30 16:12:05 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"
#include "../multi_pipex/pipex.h"

void	too_many_args(char *str, char **tab)
{
	if (str)
	{
		free (str);
		str = NULL;
	}
	ft_free_array(tab);
	ft_putstr_fd("Error: too many arguments\n", 2);
	exit (1);
}

void	numeric_argument_required(char *str, char **tab)
{
	if (str)
	{
		free (str);
		str = NULL;
	}
	ft_free_array(tab);
	ft_putstr_fd("Error: numeric argument required\n", 2);
	exit (255);
}

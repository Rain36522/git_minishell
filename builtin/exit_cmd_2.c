/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cmd_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:12:01 by cduffaut          #+#    #+#             */
/*   Updated: 2023/12/01 14:04:56 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"
#include "../Includes/header_builtin.h"

void	too_many_args(char **tab)
{
	tab = ft_free_array(tab);
	ft_putstr_fd("Error: too many arguments\n", 2);
	exit (255);
}

void	numeric_argument_required(char **tab)
{
	tab = ft_free_array(tab);
	ft_putstr_fd("Error: numeric argument required\n", 2);
	errno = 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduffaut <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:52:09 by cduffaut          #+#    #+#             */
/*   Updated: 2023/11/13 11:15:26 by cduffaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/minishell.h"

int	ft_error(int code)
{
	if (code == 1)
		ft_error_msg("command not found\n");
	else if (code == 10)
		ft_error_msg("username not found\n");
	else if (code == 11)
		ft_error_msg("error cwd\n");
	else if (code == 101)
		ft_error_msg("memory allocation failed\n");
	if (code >= 100)
		ft_quit();
	return (0);
}

void	ft_error_msg(char *msg)
{
	ft_printf("%s", msg);
}

int	ft_quit(void)
{
	// command pour tout free
	exit(1);
}

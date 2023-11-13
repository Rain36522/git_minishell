/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:52:09 by cduffaut          #+#    #+#             */
/*   Updated: 2023/11/13 11:23:28 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/minishell.h"

static void	ft_error_msg(int icode)
{
	if (icode == 1)
		ft_printf("command not found\n");
	else if (icode == 10)
		ft_printf("username not found\n");
	else if (icode == 11)
		ft_printf("error cwd\n");
	else if (icode == 101)
		ft_printf("memory allocation failed\n");
}

static void	ft_quit(void)
{
	// command pour tout free
	exit(1);
}

int	ft_error_int(int icode)
{
	ft_error_msg(icode);
	if (icode >= 100)
		ft_quit();
	return (0);
}

char	*ft_error_str(int icode)
{
	ft_error_msg(icode);
	if (icode >= 100)
		ft_quit();
	return (NULL);
}


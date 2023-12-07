/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:30:23 by pudry             #+#    #+#             */
/*   Updated: 2023/11/30 15:53:55 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	ft_error_msg(int i)
{
	ft_putstr_fd("\033[0;31m", 2);
	if (i == 9)
		ft_putstr_fd("Error : Bad file descriptor\n", 2);
	else if (i == 10)
		ft_putstr_fd("Error : No child process\n", 2);
	else if (i == 12)
		ft_putstr_fd("Error : Cannot allocate memory\n", 2);
	else if (i == 23)
		ft_putstr_fd("Error : To many open files\n", 2);
	else if (i == 22)
		ft_putstr_fd("Error : Invalid argument\n", 2);
	else if (i == 201)
		ft_putstr_fd("Error : command not found\n", 2);
	else if (i == 2)
		ft_putstr_fd("Error : No such file or directory\n", 2);
	ft_putstr_fd("\033[0m", 2);
}

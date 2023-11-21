/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:30:23 by pudry             #+#    #+#             */
/*   Updated: 2023/11/21 11:37:30 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char	*ft_error_msg(int i)
{
	ft_printf("\033[0;31m");
	if (i == 9)
		ft_printf("Error : Bad file descriptor\n");
	else if (i == 10)
		ft_printf("Error : No child process\n");
	else if (i == 12)
		ft_printf("Error : Cannot allocate memory\n");
	else if (i == 23)
		ft_printf("Error : To many open files\n");
	ft_printf("\033[0m");
}

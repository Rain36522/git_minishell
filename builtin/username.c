/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hostname.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:31:25 by cduffaut          #+#    #+#             */
/*   Updated: 2023/11/13 10:49:18 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "ft_printf/libft/libft.h"
#include "gnl/get_next_line.h"
#include <stdio.h>
#include <readline/readline.h>

//	1er error: login havn't been found
//	2eme error: failed allocation with malloc
char	*find_hostname(char **env)
{
	int		i;
	char	*login;

	i = 0;
	while (env[i] && strncmp(env[i], "LOGNAME=", 8) != 0)
		i++;
	if (env[i])
		login = ft_strdup(env[i] + 8);
	// if (!env[i])
	// 	return (ft_error(101));
	// if (!login)
	// 	return (ft_error(10));
	return (login);
}

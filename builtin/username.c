/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   username.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:31:25 by cduffaut          #+#    #+#             */
/*   Updated: 2023/11/21 15:33:50 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

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
	if (!env[i])
		return (ft_error_str(203, 0, NULL, NULL));
	if (!login)
		return (ft_error_str(203, 0, NULL, NULL));
	return (login);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:18:21 by pudry             #+#    #+#             */
/*   Updated: 2023/12/07 14:37:57 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char	*cwd(char **env)
{
	char	str[1024];
	char	*ptr;

	ptr = getcwd(str, 1024);
	if (!ptr)
		return (ft_error_ptr(12, 1, env, NULL));
	ptr = ft_strdup(str);
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:18:21 by pudry             #+#    #+#             */
/*   Updated: 2023/11/21 09:29:09 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char	*cwd(void)
{
	char	str[1024];
	char	*ptr;

	ptr = getcwd(str, 1024);
	// if (!ptr)
	// 	return (ft_error_char(5));
	ptr = ft_strdup(str);
	return (ptr);
}

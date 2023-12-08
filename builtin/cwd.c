/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:18:21 by pudry             #+#    #+#             */
/*   Updated: 2023/12/08 09:15:24 by pudry            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	pwd(char **env, char **array)
{
	char	str[1024];
	char	*ptr;

	if (array)
		ft_free_array(array);
	ptr = getcwd(str, 1024);
	if (!ptr)
		ft_error_ptr(12, 1, env, NULL);
	ft_putstr_fd(str, 1);
	ft_putchar('\n');
}

char	*cwd(char **env, char **array)
{
	char	str[1024];
	char	*ptr;

	if (array)
		ft_free_array(array);
	ptr = getcwd(str, 1024);
	if (!ptr)
		return (ft_error_ptr(12, 1, env, NULL));
	ptr = ft_strdup(str);
	if (!ptr)
		return (ft_error_ptr(12, 1, env, NULL));
	return (ptr);
}
